#include "crypto_analysis.h"

#include <cassert>

#include "bit_utils.h"
#include "text_analysis.h"
#include "xor_cipher.h"

namespace {

std::vector<std::pair<size_t, double>>
evaluate_key_sizes(const std::string &ciphertext, size_t min_key_size,
                   size_t max_key_size) {
  assert(min_key_size >= 2 && max_key_size >= 2 &&
         "Key sizes must be at least 2");
  assert(ciphertext.size() >= 4 * max_key_size &&
         "Ciphertext too short for analysis; it must be at least four times "
         "the maximum key size");

  std::vector<std::pair<size_t, double>> key_size_scores;

  for (size_t key_size = min_key_size; key_size <= max_key_size; ++key_size) {
    std::vector<std::string> blocks;
    for (size_t block_index = 0; block_index + key_size <= ciphertext.size();
         block_index += key_size) {
      blocks.push_back(ciphertext.substr(block_index, key_size));
    }

    double total_distance = 0.0;
    size_t num_distances = 0;
    size_t num_blocks = blocks.size();
    for (size_t block_index = 0;
         block_index < 4 && (block_index + 1) < blocks.size(); ++block_index) {
      int distance = bit_utils::hamming_distance(blocks[block_index],
                                                 blocks[block_index + 1]);
      total_distance += static_cast<double>(distance) / key_size;
      ++num_distances;
    }

    double normalized_distance = total_distance / num_distances;
    key_size_scores.emplace_back(std::make_pair(key_size, normalized_distance));
  }

  return key_size_scores;
}

std::vector<analysis::crypto::xor_cipher::Result>
generate_variations(const std::string &binary_data) {
  std::vector<analysis::crypto::xor_cipher::Result> results;
  results.reserve(256);

  for (int key = 0; key <= 255; ++key) {
    unsigned char xor_key = static_cast<unsigned char>(key);
    std::string message =
        crypto::xor_cipher::operations::single_byte_xor(binary_data, xor_key);
    results.emplace_back(std::move(message), xor_key);
  }
  return results;
}

std::optional<analysis::crypto::xor_cipher::Result> find_first_english_match(
    const std::vector<analysis::crypto::xor_cipher::Result> &variations,
    double chi_squared_threshold) {
  for (const auto &[text, key] : variations) {
    if (analysis::text::english::is_likely_english(text,
                                                   chi_squared_threshold)) {
      return analysis::crypto::xor_cipher::Result{text, key};
    }
  }
  return std::nullopt;
}

std::vector<analysis::crypto::xor_cipher::Result> find_all_english_matches(
    const std::vector<analysis::crypto::xor_cipher::Result> &variations,
    double chi_squared_threshold) {
  std::vector<analysis::crypto::xor_cipher::Result> matches;
  for (const auto &[text, key] : variations) {
    if (analysis::text::english::is_likely_english(text,
                                                   chi_squared_threshold)) {
      matches.emplace_back(text, key);
    }
  }
  return matches;
}

std::vector<std::string> split_into_blocks(const std::string &ciphertext,
                                           size_t block_size) {
  std::vector<std::string> blocks;
  for (size_t i = 0; i + block_size <= ciphertext.size(); i += block_size) {
    blocks.push_back(ciphertext.substr(i, block_size));
  }
  return blocks;
}

std::vector<std::string>
transpose_blocks(const std::vector<std::string> &blocks) {
  if (blocks.empty()) {
    return {};
  }

  size_t block_size = blocks[0].size();
  std::vector<std::string> transposed_blocks(block_size);

  for (const auto &block : blocks) {
    for (size_t i = 0; i < block.size(); ++i) {
      transposed_blocks[i] += block[i];
    }
  }

  return transposed_blocks;
}

} // unnamed namespace

namespace analysis::crypto::xor_cipher {

std::optional<Result> decrypt_single_byte_xor(const std::string &binary_data,
                                              double chi_squared_threshold) {
  std::vector<Result> candidates = generate_variations(binary_data);
  return find_first_english_match(candidates, chi_squared_threshold);
}

std::string repeated_xor_recover_key(const std::string &ciphertext,
                                     size_t key_size,
                                     double chi_squared_threshold) {
  std::vector<std::string> blocks = split_into_blocks(ciphertext, key_size);
  std::vector<std::string> transposed_blocks = transpose_blocks(blocks);

  std::string recovered_key;
  for (const std::string &transposed_block : transposed_blocks) {
    const std::optional<Result> result =
        decrypt_single_byte_xor(transposed_block);
    if (result.has_value()) {
      recovered_key.push_back(result->second);
    } else {
      recovered_key.push_back('?');
    }
  }
  return recovered_key;
}

std::optional<std::string>
auto_detect_repeated_xor_recover_key(const std::string &ciphertext,
                                     size_t min_key_size, size_t max_key_size,
                                     double chi_squared_threshold) {
  const std::vector<size_t> key_sizes =
      find_best_key_sizes(ciphertext, min_key_size, max_key_size, 3);

  std::string key;
  for (size_t key_size : key_sizes) {
    std::string candidate_key =
        analysis::crypto::xor_cipher::repeated_xor_recover_key(
            ciphertext, key_size, chi_squared_threshold);

    std::string plaintext = ::crypto::xor_cipher::operations::repeating_key_xor(
        ciphertext, candidate_key);
    if (analysis::text::english::is_likely_english(plaintext, 150.0)) {
      return candidate_key;
    }
  }

  return std::nullopt;
}

std::vector<size_t> find_best_key_sizes(const std::string &ciphertext,
                                        size_t min_key_size,
                                        size_t max_key_size,
                                        size_t num_key_sizes) {
  assert((max_key_size - min_key_size + 1) >= num_key_sizes &&
         "Not enough key sizes to analyze");

  std::vector<std::pair<size_t, double>> key_size_scores =
      evaluate_key_sizes(ciphertext, min_key_size, max_key_size);

  std::sort(
      key_size_scores.begin(), key_size_scores.end(),
      [](const std::pair<size_t, double> &a,
         const std::pair<size_t, double> &b) { return a.second < b.second; });

  std::vector<size_t> best_key_sizes;
  for (size_t i = 0; i < num_key_sizes && i < key_size_scores.size(); ++i) {
    best_key_sizes.push_back(key_size_scores[i].first);
  }

  return best_key_sizes;
}

} // namespace analysis::crypto::xor_cipher
