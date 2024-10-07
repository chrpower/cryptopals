#ifndef XOR_CIPHER_H
#define XOR_CIPHER_H

#include <string>

// Symmetric operation that can be used for both encryption and decryption.
namespace crypto::xor_cipher::operations {

// Performs a bitwise XOR operation on two equal-length binary data strings.
// Each byte in the first string is XORed with the corresponding byte in the
// second string.
std::string fixed_xor(const std::string &binary_data_1,
                      const std::string &binary_data_2);

// Performs a bitwise XOR operation between each byte in the input data and a
// single-byte key.
std::string single_byte_xor(const std::string &binary_data, unsigned char key);

// Performs a bitwise XOR operation between the input data and a repeating key.
// The key is repeated as necessary to match the length of the input data.
std::string repeating_key_xor(const std::string &binary_data,
                              const std::string &key);

} // namespace crypto::xor_cipher::operations

#endif // XOR_CIPHER_H
