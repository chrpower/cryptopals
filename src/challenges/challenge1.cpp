#include "challenge1.h"

#include <cassert>
#include <iostream>

#include "base64.h"
#include "hex.h"

void run_challenge_1() {
  std::cout << "Running Challenge 1..." << std::endl;

  const std::string hex_input =
      "49276d206b696c6c696e6720796f757220627261696e206c696b"
      "65206120706f69736f6e6f7573206d757368726f6f6d";
  const std::string binary_data = hex::decode(hex_input);
  const std::string base64_output = base64::encode(binary_data);

  const std::string expected_output =
      "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
  assert(
      base64_output == expected_output &&
      "Challenge 1 failed: Base64 encoding did not match the expected result!");

  std::cout << "Challenge 1 successful!" << std::endl;
}