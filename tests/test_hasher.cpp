#include "securecpp/hasher.hpp"
#include <iostream>
#include <cassert>
#include <fstream>

using namespace securecpp;

void test_sha256_string() {
    std::string input = "SecureCPP";
    std::string expectedHash = "4a372d94a5cbe1b26be22963b478fda39cf3f62bc413d625d3c23fdaed98a0ed"; // precomputed
    std::string actualHash = Hasher::sha256(input);
    assert(actualHash == expectedHash);
    std::cout << "[✔] String hashing test passed\n";
}

void test_sha256_file() {
    // Create a temp file
    std::ofstream file("temp_test.txt");
    file << "SecureCPP";
    file.close();

    std::string expectedHash = "4a372d94a5cbe1b26be22963b478fda39cf3f62bc413d625d3c23fdaed98a0ed";
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
