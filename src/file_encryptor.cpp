#include "securecpp/file_encryptor.hpp"
#include "securecpp/encryptor.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace securecpp {

void FileEncryptor::encryptFile(const std::string& inputPath, const std::string& outputPath,
                                const std::string& key, const std::string& iv) {
    std::ifstream inputFile(inputPath, std::ios::binary);
    if (!inputFile) {
        throw std::runtime_error("❌ Failed to open input file: " + inputPath);
    }

    std::ostringstream buffer;
    buffer << inputFile.rdbuf();
    std::string plaintext = buffer.str();

    std::string ciphertext = Encryptor::encrypt(plaintext, key, iv);

    std::ofstream outputFile(outputPath, std::ios::binary);
    if (!outputFile) {
        throw std::runtime_error("❌ Failed to write output file: " + outputPath);
    }

    outputFile.write(ciphertext.c_str(), ciphertext.size());
}

void FileEncryptor::decryptFile(const std::string& inputPath, const std::string& outputPath,
                                const std::string& key, const std::string& iv) {
    std::ifstream inputFile(inputPath, std::ios::binary);
    if (!inputFile) {
        throw std::runtime_error("❌ Failed to open encrypted file: " + inputPath);
    }

    std::ostringstream buffer;
    buffer << inputFile.rdbuf();
    std::string ciphertext = buffer.str();

    std::string plaintext = Encryptor::decrypt(ciphertext, key, iv);

    std::ofstream outputFile(outputPath, std::ios::binary);
    if (!outputFile) {
        throw std::runtime_error("❌ Failed to write decrypted file: " + outputPath);
    }

    outputFile.write(plaintext.c_str(), plaintext.size());
}

} // namespace securecp
