#ifndef TEXT_UTILS_H
#define TEXT_UTILS_H

#include "xor_utils.h"
#include <optional>
#include <string>
#include <vector>

namespace text_analysis {

// Returns the first valid English-like message from the XOR variations.
// The threshold for the English content detection can be customized.
// Returns an empty optional if no English-like message is found.
std::optional<xor_cipher::Result>
find_first_english_match(const std::vector<xor_cipher::Result> &variations,
                         double chi_squared_threshold = 150.0);

} // namespace text_analysis

#endif // TEXT_UTILS_H
