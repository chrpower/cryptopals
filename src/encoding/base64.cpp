#include "base64.h"

#include <array>
#include <cassert>

namespace {

constexpr std::string_view base64_alphabet =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

std::array<int, 256> generate_lookup_table() {
  std::array<int, 256> lookup{-1};
  for (int i = 0; i < 64; ++i) {
    lookup[static_cast<unsigned char>(base64_alphabet[i])] = i;
  }
  return lookup;
}

static const std::array<int, 256> base64_decode_table = generate_lookup_table();

} // namespace

namespace base64 {

std::string encode(const std::string &binary_data) {
  std::string encoded_string;
  encoded_string.reserve(((binary_data.size() + 2) / 3) * 4);

  int bit_accumulator = 0;
  int bit_count = 0;
  for (unsigned char c : binary_data) {
    bit_accumulator = (bit_accumulator << 8) | c;
    bit_count += 8;

    while (bit_count >= 6) {
      int index = (bit_accumulator >> (bit_count - 6)) & 0x3F;
      encoded_string.push_back(base64_alphabet[index]);
      bit_count -= 6;
    }
  }

  if (bit_count > 0) {
    int index = (bit_accumulator << (6 - bit_count)) & 0x3F;
    encoded_string.push_back(base64_alphabet[index]);
  }

  while (encoded_string.size() % 4 != 0) {
    encoded_string.push_back('=');
  }

  return encoded_string;
}

std::string decode(const std::string &base64_data) {
  std::string decoded_string;
  decoded_string.reserve((base64_data.size() / 4) * 3);

  int bit_accumulator = 0;
  int bit_count = 0;
  for (char c : base64_data) {
    if (c == '=') {
      break;
    }

    int index = base64_decode_table[static_cast<unsigned char>(c)];
    assert(index != std::string::npos && "Invalid Base64 character");

    bit_accumulator = (bit_accumulator << 6) | index;
    bit_count += 6;

    if (bit_count >= 8) {
      bit_count -= 8;
      decoded_string.push_back((bit_accumulator >> bit_count) & 0xFF);
    }
  }

  return decoded_string;
}
} // namespace base64