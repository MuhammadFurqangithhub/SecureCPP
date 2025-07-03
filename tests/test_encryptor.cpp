#include "securecpp/encryptor.hpp"
#include <iostream>
#include <cassert>

using namespace securecpp;

void test_aes_encryption_decryption() {
    std::string plaintext = "TopSecretMessage123";
    std::string key = "12345678901234567890123456789012"; // 32 bytes
    std::string iv = "1234567890123456";                  // 16 bytes

    std::string encrypted = Encryptor::encrypt(plaintext, key, iv);
    std::string decrypted = Encryptor::decrypt(encrypted, key, iv);

    std::cout << "🔐 AES Encryption/Decryption Test\n";
    std::cout << "Plaintext : " << plaintext << "\n";
    std::cout << "Encrypted : " << std::hex;
    for (char c : encrypted) std::cout << ((unsigned char)c < 16 ? "0" : "") << std::hex << (int)(unsigned char)c;
    std::cout << std::dec << "\n";
    std::cout << "Decrypted : " << decrypted << "\n";

    assert(decrypted == plaintext);
    std::cout << "✅ Test Passed!\n";
}

int main() {
    try {
        test_aes_encryption_decryption();
    } catch (const std::exception& e) {
        std::cerr << "❌ Exception: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
