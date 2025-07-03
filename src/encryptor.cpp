#include "securecpp/encryptor.hpp"
#include <openssl/evp.h>
#include <openssl/err.h>
#include <vector>
#include <cstring>
#include <stdexcept>

namespace securecpp {

namespace {

std::string handleOpenSSLErrors() {
    char buffer[256];
    ERR_error_string_n(ERR_get_error(), buffer, sizeof(buffer));
    return std::string(buffer);
}

void initOpenSSL() {
    static bool initialized = false;
    if (!initialized) {
        OpenSSL_add_all_algorithms();
        ERR_load_crypto_strings();
        initialized = true;
    }
}

}

std::string Encryptor::encrypt(const std::string& plaintext, const std::string& key, const std::string& iv) {
    initOpenSSL();

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) throw std::runtime_error("Failed to create EVP_CIPHER_CTX");

    const EVP_CIPHER* cipher = EVP_aes_256_cbc();
    if (key.size() != 32 || iv.size() != 16)
        throw std::runtime_error("Key must be 32 bytes and IV must be 16 bytes for AES-256-CBC");

    std::vector<unsigned char> ciphertext(plaintext.size() + EVP_CIPHER_block_size(cipher));
    int len = 0, ciphertext_len = 0;

    if (1 != EVP_EncryptInit_ex(ctx, cipher, nullptr, (const unsigned char*)key.data(), (const unsigned char*)iv.data()))
        throw std::runtime_error("EncryptInit failed: " + handleOpenSSLErrors());

    if (1 != EVP_EncryptUpdate(ctx, ciphertext.data(), &len, (const unsigned char*)plaintext.data(), plaintext.length()))
        throw std::runtime_error("EncryptUpdate failed: " + handleOpenSSLErrors());
    ciphertext_len = len;

    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext.data() + len, &len))
        throw std::runtime_error("EncryptFinal failed: " + handleOpenSSLErrors());
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return std::string((char*)ciphertext.data(), ciphertext_len);
}

std::string Encryptor::decrypt(const std::string& ciphertext, const std::string& key, const std::string& iv) {
    initOpenSSL();

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) throw std::runtime_error("Failed to create EVP_CIPHER_CTX");

    const EVP_CIPHER* cipher = EVP_aes_256_cbc();
    if (key.size() != 32 || iv.size() != 16)
        throw std::runtime_error("Key must be 32 bytes and IV must be 16 bytes for AES-256-CBC");

    std::vector<unsigned char> plaintext(ciphertext.size());
    int len = 0, plaintext_len = 0;

    if (1 != EVP_DecryptInit_ex(ctx, cipher, nullptr, (const unsigned char*)key.data(), (const unsigned char*)iv.data()))
        throw std::runtime_error("DecryptInit failed: " + handleOpenSSLErrors());

    if (1 != EVP_DecryptUpdate(ctx, plaintext.data(), &len, (const unsigned char*)ciphertext.data(), ciphertext.length()))
        throw std::runtime_error("DecryptUpdate failed: " + handleOpenSSLErrors());
    plaintext_len = len;

    if (1 != EVP_DecryptFinal_ex(ctx, plaintext.data() + len, &len))
        throw std::runtime_error("DecryptFinal failed: " + handleOpenSSLErrors());
    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return std::string((char*)plaintext.data(), plaintext_len);
}

}
