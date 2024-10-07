#include "text_analysis.h"

#include <iostream>

namespace {
bool is_printable(const std::string &text) {
  return std::all_of(text.begin(), text.end(), [](char c) {
    return isprint(static_cast<unsigned char>(c)) || c == '\n' || c == '\t';
  });
}
} // namespace

namespace analysis::text {

std::unordered_map<char, double> frequency_analysis(const std::string &text) {
  std::unordered_map<char, double> char_frequencies; //
  double total_valid_chars = 0.0;

  for (char c : text) {
    if (std::isalpha(static_cast<unsigned char>(c))) {
      c = std::toupper(static_cast<unsigned char>(c));
      char_frequencies[c] += 1.0;
      total_valid_chars += 1.0;
    } else if (c == ' ') {
      char_frequencies[' '] += 1.0;
      total_valid_chars += 1.0;
    }
  }

  for (auto &[character, frequency] : char_frequencies) {
    frequency = (frequency / total_valid_chars) * 100.0;
  }

  return char_frequencies;
}

double compare_frequencies(
    const std::unordered_map<char, double> &observed_frequencies,
    const std::unordered_map<char, double> &expected_frequencies) {
  double chi_squared_score = 0.0;

  for (const auto &[character, expected_frequency] : expected_frequencies) {
    double observed_frequency =
        (observed_frequencies.find(character) != observed_frequencies.end())
            ? observed_frequencies.at(character)
            : 0.0;
    chi_squared_score += std::pow(observed_frequency - expected_frequency, 2) /
                         expected_frequency;
  }

  return chi_squared_score;
}

namespace english {

const std::unordered_map<char, double> expected_frequencies = {
    {'A', 8.167}, {'B', 1.492}, {'C', 2.782}, {'D', 4.253}, {'E', 12.702},
    {'F', 2.228}, {'G', 2.015}, {'H', 6.094}, {'I', 6.966}, {'J', 0.153},
    {'K', 0.772}, {'L', 4.025}, {'M', 2.406}, {'N', 6.749}, {'O', 7.507},
    {'P', 1.929}, {'Q', 0.095}, {'R', 5.987}, {'S', 6.327}, {'T', 9.056},
    {'U', 2.758}, {'V', 0.978}, {'W', 2.360}, {'X', 0.150}, {'Y', 1.974},
    {'Z', 0.074}, {' ', 13.0}};

bool is_likely_english(const std::string &text, double chi_squared_threshold) {
  if (is_printable(text)) {
    const std::unordered_map<char, double> observed_frequencies =
        text::frequency_analysis(text);
    const double chi_squared_score =
        text::compare_frequencies(observed_frequencies, expected_frequencies);

    return chi_squared_score < chi_squared_threshold;
  }
  return false;
}

} // namespace english
} // namespace analysis::text
