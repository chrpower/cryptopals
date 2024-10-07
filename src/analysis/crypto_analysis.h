#ifndef CRYPTO_ANALYSIS_H
#define CRYPTO_ANALYSIS_H

#include <optional>
#include <string>
#include <vector>

namespace analysis::crypto::xor_cipher {

using Result = std::pair<std::string, unsigned char>;

// Attempts to decrypt data encrypted with a single-byte XOR cipher.
// Returns the decrypted text and the key used if successful.
std::optional<Result>
decrypt_single_byte_xor(const std::string &binary_data,
                        double chi_squared_threshold = 150.0);

// Recovers the key used in a repeating-key XOR cipher when the key size is
// known. Returns the recovered key as a string.
std::string repeated_xor_recover_key(const std::string &ciphertext,
                                     size_t key_size,
                                     double chi_squared_threshold);

// Automatically detects the key size and recovers the key for a repeating-key
// XOR cipher. Returns the recovered key if successful.
std::optional<std::string> auto_detect_repeated_xor_recover_key(
    const std::string &ciphertext, size_t min_key_size = 2,
    size_t max_key_size = 40, double chi_squared_threshold = 150.0);

// Finds the most probable key sizes for a repeating-key XOR cipher.
// Returns a vector of likely key sizes.
std::vector<size_t> find_best_key_sizes(const std::string &ciphertext,
                                        size_t min_key_size,
                                        size_t max_key_size,
                                        size_t num_key_sizes);

} // namespace analysis::crypto::xor_cipher

#endif // CRYPTO_ANALYSIS_H
