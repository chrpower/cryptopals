#ifndef BASE64_H
#define BASE64_H

#include <string>

namespace base64 {

// Encodes a string of raw binary data into a Base64-encoded string.
// Input: binary_data (a string of raw bytes).
// Output: a Base64-encoded string with characters from 'A'-'Z', 'a'-'z',
// '0'-'9', '+', '/', and '=' for padding.
std::string encode(const std::string &binary_data);

// Decodes a Base64-encoded string back into its original binary form.
// Input: base64_data (a string in Base64 format).
// Output: a string of raw bytes representing the decoded data.
std::string decode(const std::string &base64_data);

} // namespace base64

#endif // BASE64_H
