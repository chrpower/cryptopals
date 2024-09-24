#ifndef XOR_UTILS_H
#define XOR_UTILS_H

#include <string>

// Performs a bitwise XOR operation on two equal-length binary strings.
// Each character (byte) in the first string is XORed with the corresponding
// character in the second string. The function assumes that both input strings 
// are of equal length. If the strings are not of the same length, the function 
// will assert an error.
std::string fixed_xor(const std::string &str1, const std::string &str2);

#endif // XOR_UTILS_H
