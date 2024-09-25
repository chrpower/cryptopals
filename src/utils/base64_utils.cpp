#include "base64_utils.h"

std::string base64_encode(const std::string &input) {
  constexpr std::string_view base64_chars =
      "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

  std::string out;
  int bit_accumulator = 0;
  int bit_count = 0;
  for (unsigned char c : input) {
    bit_accumulator = (bit_accumulator << 8) | c;
    bit_count += 8;

    while (bit_count >= 6) {
      int index = (bit_accumulator >> (bit_count - 6)) & 0x3F;
      out.push_back(base64_chars[index]);
      bit_count -= 6;
    }
  }

  if (bit_count > 0) {
    int index = (bit_accumulator << (6 - bit_count)) & 0x3F;
    out.push_back(base64_chars[index]);
  }

  while (out.size() % 4 != 0) {
    out.push_back('=');
  }

  return out;
}