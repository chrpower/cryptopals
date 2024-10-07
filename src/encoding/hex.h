#ifndef HEX_H
#define HEX_H

#include <string>

namespace hex {

// Converts a hexadecimal string to binary data.
// Input: hex_data (a valid hex string with an even number of characters).
// Output: a string of raw bytes.
std::string decode(const std::string &hex_data);

// Converts binary data to its hexadecimal string representation.
// Input: binary_data (a string of raw bytes).
// Output: a string of hex characters (two per byte).
std::string encode(const std::string &binary_data);

} // namespace hex

#endif // HEX_H
