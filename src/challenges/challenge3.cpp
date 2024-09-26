#include "challenge3.h"

#include <cassert>
#include <iostream>

#include "hex_utils.h"
#include "text_utils.h"
#include "xor_utils.h"

void run_challenge_3() {
  std::cout << "Running Challenge 3..." << std::endl;

  const std::string hex_input =
      "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";

  const std::string binary_data = hex::decode(hex_input);
  const std::vector<xor_cipher::Result> candidates =
      xor_cipher::generate_variations(binary_data);
  const std::optional<xor_cipher::Result> result =
      text_analysis::find_first_english_match(candidates);

  assert(result.has_value() && "Challenge 3 failed: No English message found!");

  const auto &[english_message, xor_key] = result.value();
  std::string expected_output = "Cooking MC's like a pound of bacon";
  unsigned char expected_key = 88;
  assert(
      english_message == expected_output && xor_key == expected_key &&
      "Challenge 3 failed: Decoded message did not match the expected result!");

  std::cout << "Challenge 3 successful!" << std::endl;
}
