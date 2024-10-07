#ifndef BIT_UTILS_H
#define BIT_UTILS_H

#include <string>

namespace bit_utils {

// Computes the Hamming distance (number of differing bits) between two strings.
// The strings should be of equal length.
int hamming_distance(const std::string &str1, const std::string &str2);

} // namespace bit_utils

#endif // BIT_UTILS_H
