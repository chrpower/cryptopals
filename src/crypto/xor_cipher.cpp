#include <xor_cipher.h>

#include <cassert>
#include <vector>

namespace crypto::xor_cipher::operations {

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

} // namespace crypto::xor_cipher::operations