#ifndef HEX_UTILS_H
#define HEX_UTILS_H

#include <string>

namespace hex {

// Converts a hexadecimal string to binary data.
// The input is expected to be a valid hexadecimal string with an even number of
// characters. Each pair of hex characters is converted into a corresponding
// byte.
std::string decode(const std::string &hex_string);

// Converts binary data to its hexadecimal string representation.
// The input is a string of raw bytes.
// Each byte is converted to a two-character hexadecimal string.
std::string encode(const std::string &binary_data);

} // namespace hex

#endif // HEX_UTILS_H