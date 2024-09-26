#ifndef BASE64_UTILS_H
#define BASE64_UTILS_H

#include <string>

namespace base64 {

// Converts binary data to a Base64-encoded string.
// The input is a string of raw bytes.
// The output is a Base64-encoded string containing only characters from the
// Base64 alphabet ('A'-'Z', 'a'-'z', '0'-'9', '+', '/', and '=' for padding).
std::string encode(const std::string &binary_data);

} // namespace base64

#endif // BASE64_UTILS_H
