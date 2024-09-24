cmake_minimum_required(VERSION 3.10)
project(Cypropals)

set(CMAKE_CXX_STANDARD 20)

include_directories(src/utils src/challenges)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(Cypropals
        src/main.cpp
        src/challenges/challenge1.cpp
        src/challenges/challenge2.cpp
        src/utils/base64_utils.cpp
        src/utils/hex_utils.cpp
        src/utils/xor_utils.cpp
)