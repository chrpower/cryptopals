#ifndef HEX_UTILS_H
#define HEX_UTILS_H

#include <string>

// Converts a hexadecimal string to a binary (byte) string.
// The input is expected to be a valid hex string with an even number of
// characters. Each pair of hex characters is converted into a corresponding
// byte.
std::string hex_to_bytes(const std::string &hex);

// Converts a binary (byte) string to its hexadecimal string representation.
// The input is a string of raw bytes, and each byte is converted to a
// two-character hex string.
std::string bytes_to_hex(const std::string &bytes);

#endif // HEX_UTILS_H