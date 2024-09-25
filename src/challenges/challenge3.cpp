#include "challenge3.h"

#include <cassert>
#include <iostream>

#include "hex_utils.h"
#include "text_utils.h"
#include "xor_utils.h"

void run_challenge_3() {
  std::cout << "Running Challenge 3..." << std::endl;

  std::string hex_input =
      "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
  std::string decoded_bytes = hex_to_bytes(hex_input);

  std::string decoded_message;
  unsigned char key = 0;
  for (unsigned char i = 0; i < 255; ++i) {
    std::string xor_output = single_byte_xor(decoded_bytes, i);
    if (is_english_content(xor_output)) {
      decoded_message = xor_output;
      key = i;
      break;
    }
  }

  std::string expected_output = "Cooking MC's like a pound of bacon";
  unsigned char expected_key = 'X';
  assert(
      decoded_message == expected_output && key == expected_key &&
      "Challenge 3 failed: Decoded message did not match the expected result!");

  std::cout << "Challenge 3 successful!" << std::endl;
}
