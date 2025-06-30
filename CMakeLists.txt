cmake_minimum_required(VERSION 3.10)
project(SecureCPP)

set(CMAKE_CXX_STANDARD 17)

# Include headers
include_directories(include)

# Collect source files
file(GLOB_RECURSE SECURECPP_SOURCES src/*.cpp)

# Add SecureCPP library
add_library(SecureCPP STATIC ${SECURECPP_SOURCES})

# Link OpenSSL
find_package(OpenSSL REQUIRED)
target_link_libraries(SecureCPP OpenSSL::SSL OpenSSL::Crypto)

# ====================
# Test: test_main
add_executable(test_main tests/test_main.cpp)
target_link_libraries(test_main SecureCPP)

# Test: test_hasher
add_executable(test_hasher tests/test_hasher.cpp)
target_link_libraries(test_hasher SecureCPP)
