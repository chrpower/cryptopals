#ifndef XOR_UTILS_H
#define XOR_UTILS_H

#include <string>
#include <utility>
#include <vector>

namespace xor_cipher {

// Type alias for the result of an XOR operation.
// Consists of a string (the processed data) and an unsigned char (the XOR key).
using Result = std::pair<std::string, unsigned char>;

// Performs a bitwise XOR operation on two equal-length binary data strings.
// Each byte in the first string is XORed with the corresponding byte in the
// second string. The function assumes that both input strings are of equal
// length. If the strings are not of the same length, the behavior is undefined.
std::string fixed_xor(const std::string &binary_data_1,
                      const std::string &binary_data_2);

// Performs a bitwise XOR operation between each byte in the input data
// and a single-byte key. The same key is applied to each byte in the input
// data.
std::string single_byte_xor(const std::string &binary_data, unsigned char key);

// Performs a bitwise XOR operation between the input data and a repeating key.
// The key is repeated as necessary to match the length of the input data.
// Each byte in the input data is XORed with the corresponding byte in the key.
// Returns a string containing the result of the XOR operation.
std::string repeating_key_xor(const std::string &binary_data,
                              const std::string &key);

// Generates all possible single-byte XOR variations for the given input data.
// It applies XOR for each key value from 0 to 255 and returns a vector of
// Results, where each Result contains the processed data and the corresponding
// XOR key.
std::vector<Result> generate_variations(const std::string &binary_data);

} // namespace xor_cipher

#endif // XOR_UTILS_H
