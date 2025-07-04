#ifndef SECURECPP_FILEENCRYPTOR_HPP
#define SECURECPP_FILEENCRYPTOR_HPP

#include <string>

namespace securecpp {

class FileEncryptor {
public:
    // Encrypts file from inputPath -> outputPath using AES key & iv
    static void encryptFile(const std::string& inputPath, const std::string& outputPath,
                            const std::string& key, const std::string& iv);

    // Decrypts file from inputPath -> outputPath using AES key & iv
    static void decryptFile(const std::string& inputPath, const std::string& outputPath,
                            const std::string& key, const std::string& iv);
};

} 

#endif 
