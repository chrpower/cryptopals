cmake_minimum_required(VERSION 3.10)
project(Cryptopals)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 20)

# Include directories
include_directories(src/analysis src/challenges src/crypto src/encoding src/utils)

# Set the output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Set OpenSSL root directory
set(OpenSSL_ROOT_DIR /usr/local/opt/openssl@3)  # Adjust the path as necessary

# Find OpenSSL
find_package(OpenSSL REQUIRED)

# Add executable
add_executable(Cryptopals
    src/main.cpp
    src/analysis/crypto_analysis.cpp
    src/analysis/text_analysis.cpp
    src/challenges/challenge1.cpp
    src/challenges/challenge2.cpp
    src/challenges/challenge3.cpp
    src/challenges/challenge4.cpp
    src/challenges/challenge5.cpp
    src/challenges/challenge6.cpp
    src/challenges/challenge7.cpp
    src/crypto/aes_cipher.cpp
    src/crypto/xor_cipher.cpp
    src/encoding/base64.cpp
    src/encoding/hex.cpp
    src/utils/file_io.cpp
    src/utils/bit_utils.cpp
)

# Link OpenSSL libraries
target_link_libraries(Cryptopals PRIVATE OpenSSL::SSL OpenSSL::Crypto)
