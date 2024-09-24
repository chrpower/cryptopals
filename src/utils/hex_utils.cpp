#include "hex_utils.h"
#include <cassert>

namespace {
  int hex_char_to_int(char c) {
    assert((c >= '0' && c <= '9') ||
         (c >= 'a' && c <= 'f') ||
         (c >= 'A' && c <= 'F'));

    if (c >= '0' && c <= '9')
      return c - '0';
    else if (c >= 'a' && c <= 'f')
      return c - 'a' + 10;
    else // c >= 'A' && c <= 'F'
      return c - 'A' + 10;
  }
}
std::string hex_to_bytes(const std::string &hex) {
  assert(hex.length() % 2 == 0);

  std::string bytes;
  bytes.reserve(hex.length() / 2);
  for (size_t i = 0; i < hex.length(); i += 2) {
    int high = hex_char_to_int(hex[i]);
    int low = hex_char_to_int(hex[i + 1]);
    bytes.push_back((high << 4) | low);
  }
  return bytes;
}
