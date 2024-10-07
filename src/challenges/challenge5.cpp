#include "challenge5.h"

#include <cassert>
#include <iostream>
#include <stdexcept>
#include <string>

#include "hex.h"
#include "xor_cipher.h"

void run_challenge_5() {
  std::cout << "Running Challenge 5..." << std::endl;

  const std::string plaintext = "Burning 'em, if you ain't quick and nimble\n"
                                "I go crazy when I hear a cymbal";
  const std::string key = "ICE";

  const std::string encrypted_binary =
      crypto::xor_cipher::operations::repeating_key_xor(plaintext, key);
  const std::string encrypted_hex = hex::encode(encrypted_binary);

  const std::string expected_output =
      "0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765"
      "272a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27"
      "282f";

  assert(encrypted_hex == expected_output &&
         "Challenge 4 failed: Entypted_hex did not match the expected result!");

  std::cout << "Challenge 5 successful!" << std::endl;
}