#include "challenge2.h"

#include <cassert>
#include <iostream>

#include "hex_utils.h"
#include "xor_utils.h"

void run_challenge_2() {
  std::cout << "Running Challenge 2..." << std::endl;

  const std::string hex_input1 = "1c0111001f010100061a024b53535009181c";
  const std::string binary_data1 = hex::decode(hex_input1);

  const std::string hex_input2 = "686974207468652062756c6c277320657965";
  const std::string binary_data2 = hex::decode(hex_input2);

  const std::string xor_output =
      xor_cipher::fixed_xor(binary_data1, binary_data2);
  const std::string hex_output = hex::encode(xor_output);

  const std::string expected_output = "746865206b696420646f6e277420706c6179";
  assert(hex_output == expected_output &&
         "Challenge 2 failed: XOR result did not match the expected result!");

  std::cout << "Challenge 2 successful!" << std::endl;
}