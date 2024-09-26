#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string>
#include <vector>

namespace file_utils {

// Reads all lines from a file and returns them as a vector of strings.
// Each line in the file corresponds to one element in the vector.
std::vector<std::string> read_file_lines(const std::string &file_path);

} // namespace file_utils

#endif // FILE_UTILS_H