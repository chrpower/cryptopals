#include "hex_utils.h"

#include <cassert>

namespace {
int hex_char_to_int(char c) {
  assert((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') ||
         (c >= 'A' && c <= 'F'));

  if (c >= '0' && c <= '9')
    return c - '0';
  else if (c >= 'a' && c <= 'f')
    return c - 'a' + 10;
  else // c >= 'A' && c <= 'F'
    return c - 'A' + 10;
}
} // namespace

namespace hex {

std::string decode(const std::string &hex_string) {
  assert(hex_string.length() % 2 == 0);

  std::string bytes;
  bytes.reserve(hex_string.length() / 2);
  for (size_t i = 0; i < hex_string.length(); i += 2) {
    int high = hex_char_to_int(hex_string[i]);
    int low = hex_char_to_int(hex_string[i + 1]);
    bytes.push_back((high << 4) | low);
  }
  return bytes;
}

std::string encode(const std::string &binary_data) {
  constexpr std::string_view hex_chars = "0123456789abcdef";

  std::string hex_string;
  hex_string.reserve(binary_data.length() * 2);
  for (unsigned char c : binary_data) {
    hex_string.push_back(hex_chars[(c >> 4) & 0x0F]);
    hex_string.push_back(hex_chars[c & 0x0F]);
  }
  return hex_string;
}
} // namespace hex