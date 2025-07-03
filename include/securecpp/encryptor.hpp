#ifndef SECURECPP_ENCRYPTOR_HPP
#define SECURECPP_ENCRYPTOR_HPP

#include <string>

namespace securecpp {

class Encryptor {
public:
    static std::string encrypt(const std::string& plaintext, const std::string& key, const std::string& iv);
    static std::string decrypt(const std::string& ciphertext, const std::string& key, const std::string& iv);
};

}

#endif // SECURECPP_ENCRYPTOR_HPP
