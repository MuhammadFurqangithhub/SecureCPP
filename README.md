# 🔐 SecureCPP

**SecureCPP** is a high-performance, modular, and cross-platform C++17 security library built for modern systems.  
It provides essential cryptographic utilities like hashing, encryption, password protection, and secure memory handling — all in clean, testable C++ code.

---

## ⚡ Features

✅ SHA256, SHA512, BLAKE2 Hashing  
✅ AES-128 & AES-256 Encryption (CBC/CTR)  
✅ HMAC for Message Authentication  
✅ Salted Password Hashing with PBKDF2  
✅ Base64 and Hex Encoding/Decoding  
✅ Secure Memory Wiping Utilities  
✅ Header-only convenience wherever possible  
✅ CMake-based cross-platform build

---

## 📁 Project Structure

```
SecureCPP/
├── include/SecureCPP/      → Public header files
├── src/                    → Internal source files
├── tests/                  → Unit tests
├── examples/               → Example usages
├── cli/                    → Command-line tools (optional)
├── CMakeLists.txt          → Build configuration
├── README.md               → Project overview
└── LICENSE                 → MIT License
```

---

## 🧪 Getting Started

### 🔧 Prerequisites
- C++17-compatible compiler (g++, clang++, MSVC)
- CMake 3.10+
- Optional: OpenSSL (for extended cryptography)

### ⚙️ Build Instructions

```bash
git clone https://github.com/MuhammadFurqangithhub/SecureCPP.git
cd SecureCPP
mkdir build && cd build
cmake ..
make
./test_main  # run tests
```

---

## 🚀 Usage Example

Here's how simple it will be to use hashing:

```cpp
#include "SecureCPP/Hasher.hpp"

int main() {
    std::string input = "HelloSecureCPP";
    std::string hash = SecureCPP::Hasher::sha256(input);
    std::cout << "SHA256: " << hash << std::endl;
    return 0;
}
```

> More usage examples will be added in the `examples/` directory as modules are developed.

---

## 🛠 Modules Roadmap

| Module           | Status     | Description                              |
|------------------|------------|------------------------------------------|
| Hasher           | 🚧 WIP      | SHA256, SHA512, BLAKE2 hashing           |
| Encryptor        | 🔜 Planned | AES-CBC, CTR modes                       |
| PasswordManager  | 🔜 Planned | PBKDF2 salted password hashing           |
| HMAC             | 🔜 Planned | Message integrity verification           |
| Base64 & Hex     | 🔜 Planned | Encoding/decoding helpers                |
| SecureUtils      | 🔜 Planned | Secure memory operations                 |
| CLI Tool         | 🔜 Planned | Command-line wrapper for the library     |

---

## 🤝 Contributing

If you'd like to contribute:

- Fork this repo
- Create a branch (`feature/YourFeature`)
- Push commits
- Open a Pull Request 🚀

---

## 📄 License

This project is licensed under the **MIT License** — see the [LICENSE](./LICENSE) file for details.

---

## 🔗 Connect

- 💻 GitHub: [@MuhammadFurqangithhub](https://github.com/MuhammadFurqangithhub)
- 📖 Medium: [@muhammadfurqan17](https://medium.com/@muhammadfurqan17)
- 👔 LinkedIn: [@m-furqan](https://www.linkedin.com/in/m-furqan/)

> _Secure code, secure future. Let’s build something powerful._ 💪
