#include "xor_utils.h"

#include <cassert>
#include <string>
#include <vector>

namespace xor_cipher {

std::string fixed_xor(const std::string &binary_data1,
                      const std::string &binary_data2) {
  assert(binary_data1.size() == binary_data2.size() &&
         "Input must be of equal length");

  std::string result;
  result.reserve(binary_data1.size());
  for (size_t i = 0; i < binary_data1.length(); ++i) {
    result.push_back(binary_data1[i] ^ binary_data2[i]);
  }
  return result;
}

std::string single_byte_xor(const std::string &binary_data, unsigned char key) {
  std::string result;
  result.reserve(binary_data.size());
  for (unsigned char c : binary_data) {
    result.push_back(c ^ key);
  }
  return result;
}

std::string repeating_key_xor(const std::string &binary_data,
                              const std::string &key) {
  std::string result;
  result.reserve(binary_data.size());
  for (size_t i = 0; i < binary_data.size(); ++i) {
    unsigned char data_byte = static_cast<unsigned char>(binary_data[i]);
    unsigned char key_byte = static_cast<unsigned char>(key[i % key.size()]);
    result.push_back(data_byte ^ key_byte);
  }
  return result;
}

std::vector<xor_cipher::Result>
generate_variations(const std::string &binary_data) {
  std::vector<xor_cipher::Result> results;
  results.reserve(256);

  for (int key = 0; key <= 255; ++key) {
    unsigned char xor_key = static_cast<unsigned char>(key);
    std::string message = single_byte_xor(binary_data, xor_key);
    results.emplace_back(std::move(message), xor_key);
  }
  return results;
}

} // namespace xor_cipher