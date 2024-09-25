#include "challenge2.h"

#include <cassert>
#include <iostream>

#include "hex_utils.h"
#include "xor_utils.h"

void run_challenge_2() {
  std::cout << "Running Challenge 2..." << std::endl;

  std::string hex_input_1 = "1c0111001f010100061a024b53535009181c";
  std::string decoded_bytes_1 = hex_to_bytes(hex_input_1);

  std::string hex_input_2 = "686974207468652062756c6c277320657965";
  std::string decoded_bytes_2 = hex_to_bytes(hex_input_2);

  std::string xor_output = fixed_xor(decoded_bytes_1, decoded_bytes_2);
  std::string hex_output = bytes_to_hex(xor_output);

  std::string expected_output = "746865206b696420646f6e277420706c6179";
  assert(hex_output == expected_output &&
         "Challenge 2 failed: XOR result did not match the expected result!");

  std::cout << "Challenge 2 successful!" << std::endl;
}