#ifndef TEXT_UTILS_H
#define TEXT_UTILS_H

#include <string>

// This function uses the chi-squared test to compare the letter frequency
// of the input string to typical English letter frequencies. The calculated
// chi-squared value is compared to a given threshold to assess whether
// the content is likely to be English.
bool is_english_content(const std::string &content, double threshold = 150.0);

#endif // TEXT_UTILS_H
