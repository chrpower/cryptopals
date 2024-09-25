#ifndef BASE64_UTILS_H
#define BASE64_UTILS_H

#include <string>

// This function converts the input binary data into a Base64-encoded string,
// which is a commonly used encoding for representing binary data in a textual
// format using ASCII characters. The encoded string will contain only
// characters from the Base64 alphabet ('A'-'Z', 'a'-'z', '0'-'9', '+', '/', and
// '=' for padding).
std::string base64_encode(const std::string &input);

#endif // BASE64_UTILS_H
