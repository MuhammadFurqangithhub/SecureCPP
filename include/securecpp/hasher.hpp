#ifndef SECURECPP_HASHER_HPP
#define SECURECPP_HASHER_HPP

#include <string>

namespace securecpp {

class Hasher {
public:
    // Returns SHA256 hash of a given string
    static std::string sha256(const std::string& input);

    // Returns SHA256 hash of a file's content
    static std::string sha256FromFile(const std::string& filepath);
};

} // namespace securecpp

#endif // SECURECPP_HASHER_HPP
