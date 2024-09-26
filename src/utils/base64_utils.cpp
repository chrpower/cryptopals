#include "base64_utils.h"

namespace base64 {

std::string encode(const std::string &binary_data) {
  constexpr std::string_view base64_chars =
      "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

  std::string encoded_string;
  encoded_string.reserve(((binary_data.size() + 2) / 3) * 4);

  int bit_accumulator = 0;
  int bit_count = 0;
  for (unsigned char c : binary_data) {
    bit_accumulator = (bit_accumulator << 8) | c;
    bit_count += 8;

    while (bit_count >= 6) {
      int index = (bit_accumulator >> (bit_count - 6)) & 0x3F;
      encoded_string.push_back(base64_chars[index]);
      bit_count -= 6;
    }
  }

  if (bit_count > 0) {
    int index = (bit_accumulator << (6 - bit_count)) & 0x3F;
    encoded_string.push_back(base64_chars[index]);
  }

  while (encoded_string.size() % 4 != 0) {
    encoded_string.push_back('=');
  }

  return encoded_string;
}
} // namespace base64