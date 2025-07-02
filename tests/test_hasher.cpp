#include "securecpp/hasher.hpp"
#include <iostream>
#include <cassert>
#include <fstream>

using namespace securecpp;

void test_sha256_string() {
    std::cout << "🔐 Testing Hasher Module\n";
    std::string input = "SecureCPP";
    std::string expectedHash = "3af7f72e7393776347079d9ac65be2fd8163014dfb4e71267bcc60aa67c37ce3";

    std::string actualHash = securecpp::Hasher::sha256(input);

    // 🔍 Debug Output
    std::cout << "Expected: " << expectedHash << std::endl;
    std::cout << "Actual  : " << actualHash << std::endl;

    assert(actualHash == expectedHash);
    std::cout << "[✔] String hashing test passed\n";
}

void test_sha256_file() {
    // Create a temp file
    std::ofstream file("temp_test.txt");
    file << "SecureCPP";
    file.close();

    std::string expectedHash = "3af7f72e7393776347079d9ac65be2fd8163014dfb4e71267bcc60aa67c37ce3";
    std::string actualHash = Hasher::sha256FromFile("temp_test.txt");
    assert(actualHash == expectedHash);
    std::cout << "[✔] File hashing test passed\n";

    std::remove("temp_test.txt");
}

int main() {
    std::cout << "🔐 Testing Hasher Module\n";
    test_sha256_string();
    test_sha256_file();
    std::cout << "✅ All tests passed.\n";
    return 0;
}
