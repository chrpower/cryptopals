#include <cassert>
#include <string>

std::string fixed_xor(const std::string &str1, const std::string &str2) {
  assert(str1.size() == str2.size() && "Input strings must be of equal length");

  std::string out;
  out.reserve(str1.size());
  for (size_t i = 0; i < str1.length(); ++i) {
    out.push_back(str1[i] ^ str2[i]);
  }
  return out;
}

std::string single_byte_xor(const std::string &input, char key) {
  std::string out;
  out.reserve(input.size());
  for (char c : input) {
    out.push_back(c ^ key);
  }
  return out;
}