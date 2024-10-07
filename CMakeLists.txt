cmake_minimum_required(VERSION 3.10)
project(Cypropals)

set(CMAKE_CXX_STANDARD 20)

include_directories(src/analysis src/challenges src/crypto src/encoding src/utils)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(Cypropals
        src/main.cpp
        src/analysis/crypto_analysis.cpp
        src/analysis/text_analysis.cpp
        src/challenges/challenge1.cpp
        src/challenges/challenge2.cpp
        src/challenges/challenge3.cpp
        src/challenges/challenge4.cpp
        src/challenges/challenge5.cpp
        src/challenges/challenge6.cpp
        src/crypto/xor_cipher.cpp
        src/encoding/base64.cpp
        src/encoding/hex.cpp
        src/utils/file_io.cpp
        src/utils/bit_utils.cpp
)
 