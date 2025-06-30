#include "securecpp/hasher.hpp"
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>
#include <fstream>

namespace securecpp {

std::string toHex(const unsigned char* hash, std::size_t length) {
    std::ostringstream result;
    for (std::size_t i = 0; i < length; ++i) {
        result << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    return result.str();
}

std::string Hasher::sha256(const std::string& input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(input.c_str()), input.size(), hash);
    return toHex(hash, SHA256_DIGEST_LENGTH);
}

std::string Hasher::sha256FromFile(const std::string& filepath) {
    std::ifstream file(filepath, std::ios::binary);
    if (!file) {
        return "";
    }

    SHA256_CTX ctx;
    SHA256_Init(&ctx);

    char buffer[8192];
    while (file.read(buffer, sizeof(buffer))) {
        SHA256_Update(&ctx, buffer, file.gcount());
    }
    // Handle last read if any
    if (file.gcount() > 0) {
        SHA256_Update(&ctx, buffer, file.gcount());
    }

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_Final(hash, &ctx);

    return toHex(hash, SHA256_DIGEST_LENGTH);
}

} // namespace securecpp
