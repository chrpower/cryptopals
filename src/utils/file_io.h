#ifndef FILE_IO_H
#define FILE_IO_H

#include <string>
#include <vector>

namespace file_io {

// Reads all lines from the specified file and returns them as a vector of
// strings. Each line in the file corresponds to one element in the vector.
// Newline characters ('\n' and '\r') are removed from the end of each line.
std::vector<std::string> read_file_as_lines(const std::string &file_path);

// Reads the entire contents of the specified file and returns it as a single
// string. The function removes all newline characters ('\n' and '\r') from the
// file content.
std::string read_file_as_string(const std::string &file_path);

} // namespace file_io

#endif // FILE_IO_H
