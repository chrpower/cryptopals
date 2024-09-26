#include "challenge4.h"

#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

#include <base64_utils.h>
#include <file_utils.h>
#include <hex_utils.h>
#include <text_utils.h>
#include <xor_utils.h>

void run_challenge_4() {
  std::cout << "Running Challenge 4..." << std::endl;

  const std::vector<std::string> hex_strings =
      file_utils::read_file_lines("data/challenge4_input.txt");

  std::optional<xor_cipher::Result> result;
  for (const auto &hex_input : hex_strings) {
    const std::string binary_data = hex::decode(hex_input);
    const std::vector<xor_cipher::Result> candidates =
        xor_cipher::generate_variations(binary_data);
    result = text_analysis::find_first_english_match(candidates);
    if (result.has_value()) {
      break;
    }
  }

  assert(result.has_value() && "Challenge 4 failed: No English message found!");

  const auto &[english_message, xor_key] = result.value();
  std::string expected_output = "Now that the party is jumping\n";
  unsigned char expected_key = 53;
  assert(
      english_message == expected_output && xor_key == expected_key &&
      "Challenge 4 failed: Decoded message did not match the expected result!");

  std::cout << "Challenge 4 successful!" << std::endl;
}