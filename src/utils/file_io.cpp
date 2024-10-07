#include "file_io.h"

#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>

namespace file_io {

std::vector<std::string> read_file_as_lines(const std::string &file_path) {
  std::ifstream file(file_path);
  assert(file.is_open() && "Error: Could not open the file");

  std::vector<std::string> lines;
  std::string line;
  while (std::getline(file, line)) {
    line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
    line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
    lines.push_back(std::move(line));
  }
  return lines;
}

std::string read_file_as_string(const std::string &file_path) {
  std::ifstream file(file_path);
  assert(file.is_open() && "Error: Could not open the file");

  std::string content((std::istreambuf_iterator<char>(file)),
                      std::istreambuf_iterator<char>());
  content.erase(std::remove(content.begin(), content.end(), '\r'),
                content.end());
  content.erase(std::remove(content.begin(), content.end(), '\n'),
                content.end());
  return content;
}

} // namespace file_io
