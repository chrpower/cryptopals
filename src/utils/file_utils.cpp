#include "file_utils.h"

#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>

namespace file_utils {

std::vector<std::string> read_file_lines(const std::string &file_path) {
  std::ifstream file(file_path);
  assert(file.is_open() && "Error: Could not open the file");

  std::vector<std::string> lines;
  std::string line;
  while (std::getline(file, line)) {
    line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
    line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
    lines.push_back(line);
  }
  return lines;
}

} // namespace file_utils
