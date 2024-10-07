#ifndef TEXT_ANALYSIS_H
#define TEXT_ANALYSIS_H

#include <string>
#include <unordered_map>

namespace analysis::text {

// Analyzes the frequency of characters in the input text.
// Returns a map of characters to their frequency percentages.
std::unordered_map<char, double> frequency_analysis(const std::string &text);

// Calculates the chi-squared statistic between observed and expected
// frequencies. Returns the chi-squared score indicating similarity.
double compare_frequencies(const std::unordered_map<char, double> &observed,
                           const std::unordered_map<char, double> &expected);

namespace english {

// Determines if the given text is likely English based on chi-squared analysis.
// Returns true if the text is likely English.
bool is_likely_english(const std::string &text,
                       double chi_squared_threshold = 150.0);

} // namespace english
} // namespace analysis::text

#endif // TEXT_ANALYSIS_H
