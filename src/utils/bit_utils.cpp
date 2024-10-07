#include "bit_utils.h"

#include <cassert>

namespace bit_utils {

int hamming_distance(const std::string &str1, const std::string &str2) {
  assert(str1.size() == str2.size() &&
         "Strings must be of equal length to compute Hamming distance");

  int distance = 0;
  for (size_t i = 0; i < str1.size(); ++i) {
    unsigned char xor_result = static_cast<unsigned char>(str1[i] ^ str2[i]);
    while (xor_result) {
      xor_result &= xor_result - 1;
      ++distance;
    }
  }
  return distance;
}

} // namespace bit_utils
