#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>

namespace {
const std::unordered_map<char, double> expected_frequencies = {
    {'A', 8.167}, {'B', 1.492}, {'C', 2.782}, {'D', 4.253}, {'E', 12.702},
    {'F', 2.228}, {'G', 2.015}, {'H', 6.094}, {'I', 6.966}, {'J', 0.153},
    {'K', 0.772}, {'L', 4.025}, {'M', 2.406}, {'N', 6.749}, {'O', 7.507},
    {'P', 1.929}, {'Q', 0.095}, {'R', 5.987}, {'S', 6.327}, {'T', 9.056},
    {'U', 2.758}, {'V', 0.978}, {'W', 2.360}, {'X', 0.150}, {'Y', 1.974},
    {'Z', 0.074}};

double chi_squared_test(const std::string &input) {
  std::unordered_map<char, int> letter_counts;
  int total_letters = 0;

  for (char c : input) {
    if (std::isalpha(static_cast<unsigned char>(c))) {
      c = std::toupper(static_cast<unsigned char>(c));
      letter_counts[c]++;
      ++total_letters;
    }
  }

  if (total_letters == 0) {
    return std::numeric_limits<double>::infinity();
  }

  double chi_squared = 0.0;
  const double total_letters_as_double =
      static_cast<double>(total_letters); // Avoid repeated casting
  for (const auto &[letter, expected_freq] : expected_frequencies) {
    double observed_freq =
        (letter_counts[letter] / total_letters_as_double) * 100.0;
    chi_squared += std::pow(observed_freq - expected_freq, 2) / expected_freq;
  }

  return chi_squared;
}
} // namespace

bool is_english_content(const std::string &content, double threshold) {
  return chi_squared_test(content) < threshold;
}