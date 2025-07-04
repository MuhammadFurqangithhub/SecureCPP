#include "securecpp/file_encryptor.hpp"
#include <iostream>
#include <fstream>
#include <cassert>

using namespace securecpp;

void test_file_encryption_decryption() {
    std::string originalText = "Confidential file contents.\nLine 2.\nLine 3.";
    std::string inputPath = "tests/testdata/input.txt";
    std::string encPath = "tests/testdata/encrypted.enc";
    std::string decPath = "tests/testdata/decrypted.txt";

    std::string key = "12345678901234567890123456789012"; // 32 bytes
    std::string iv  = "1234567890123456";                 // 16 bytes

    // Create sample input file
    std::ofstream inputFile(inputPath);
    inputFile << originalText;
    inputFile.close();

    // Encrypt it
    FileEncryptor::encryptFile(inputPath, encPath, key, iv);
    std::cout << "🔐 Encrypted " << inputPath << " -> " << encPath << "\n";

    // Decrypt it
    FileEncryptor::decryptFile(encPath, decPath, key, iv);
    std::cout << "🔓 Decrypted " << encPath << " -> " << decPath << "\n";

    // Validate content
    std::ifstream outputFile(decPath);
    std::string result((std::istreambuf_iterator<char>(outputFile)),
                       std::istreambuf_iterator<char>());

    std::cout << "✅ Decrypted Output:\n" << result << "\n";
    assert(result == originalText);
    std::cout << "🎉 File encryption/decryption test passed!\n";
}

int main() {
    test_file_encryption_decryption();
    return 0;
}
