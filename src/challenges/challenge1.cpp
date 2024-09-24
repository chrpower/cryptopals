#include <iostream>
#include <cassert>
#include "challenge1.h"
#include "base64_utils.h"
#include "hex_utils.h"

void run_challenge_1() {
  std::cout << "Running Challenge 1..." << std::endl;

  std::string hex_input = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
  std::string decoded_bytes = hex_to_bytes(hex_input);
  std::string base64_output = base64_encode(decoded_bytes);

  std::string expected_output = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";

  assert(base64_output == expected_output && "Challenge 1 failed: Base64 encoding did not match the expected result!");

  std::cout << "Challenge 1 successful!" << std::endl;
}