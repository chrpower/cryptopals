#include "xor_utils.h"

#include <cctype>
#include <cmath>
#include <iostream>
#include <optional>
#include <string>
#include <unordered_map>

namespace {

const std::unordered_map<char, double> expected_frequencies = {
    {'A', 8.167}, {'B', 1.492}, {'C', 2.782}, {'D', 4.253}, {'E', 12.702},
    {'F', 2.228}, {'G', 2.015}, {'H', 6.094}, {'I', 6.966}, {'J', 0.153},
    {'K', 0.772}, {'L', 4.025}, {'M', 2.406}, {'N', 6.749}, {'O', 7.507},
    {'P', 1.929}, {'Q', 0.095}, {'R', 5.987}, {'S', 6.327}, {'T', 9.056},
    {'U', 2.758}, {'V', 0.978}, {'W', 2.360}, {'X', 0.150}, {'Y', 1.974},
    {'Z', 0.074}, {' ', 13.0}};

bool is_printable(const std::string &text) {
  return std::all_of(text.begin(), text.end(), [](char c) {
    return isprint(static_cast<unsigned char>(c)) || c == '\n' || c == '\t';
  });
}

double calculate_chi_squared(const std::string &text) {
  std::unordered_map<char, int> char_counts;
  int total_chars = 0;

  for (char c : text) {
    if (std::isalpha(static_cast<unsigned char>(c))) {
      c = std::toupper(static_cast<unsigned char>(c));
      char_counts[c]++;
      ++total_chars;
    } else if (c == ' ') {
      char_counts[' ']++;
      ++total_chars;
    }
  }

  if (total_chars == 0) {
    return std::numeric_limits<double>::infinity();
  }

  double chi_squared = 0.0;
  const double total_chars_as_double = static_cast<double>(total_chars);
  for (const auto &[char_key, expected_freq] : expected_frequencies) {
    double observed_freq =
        (static_cast<double>(char_counts[char_key]) / total_chars_as_double) *
        100.0;
    chi_squared += std::pow(observed_freq - expected_freq, 2) / expected_freq;
  }

  return chi_squared;
}

bool is_likely_english(const std::string &text, double threshold = 150.0) {
  return calculate_chi_squared(text) < threshold;
}
} // unnamed namespace

namespace text_analysis {

std::optional<xor_cipher::Result>
find_first_english_match(const std::vector<xor_cipher::Result> &candidates,
                         double threshold = 150.0) {
  for (const auto &[text, key] : candidates) {
    if (is_printable(text) && is_likely_english(text, threshold)) {
      return xor_cipher::Result{text, key};
    }
  }
  return std::nullopt;
}

} // namespace text_analysis
