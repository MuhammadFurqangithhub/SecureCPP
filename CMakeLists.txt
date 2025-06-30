cmake_minimum_required(VERSION 3.10)
project(SecureCPP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Source files
file(GLOB_RECURSE SECURECPP_SOURCES src/*.cpp)

# Create static library
#add_library(SecureCPP STATIC ${SECURECPP_SOURCES})

# Build test executable
add_executable(test_main tests/test_main.cpp)
#target_link_libraries(test_main SecureCPP)

# Optional: CLI tool
if(EXISTS "${CMAKE_SOURCE_DIR}/cli/main.cpp")
    add_executable(securecpp_cli cli/main.cpp)
    target_link_libraries(securecpp_cli SecureCPP)
endif()
