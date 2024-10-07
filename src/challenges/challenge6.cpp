#include "challenge6.h"

#include <cassert>
#include <iostream>
#include <optional>

#include "base64.h"
#include "crypto_analysis.h"
#include "file_io.h"

namespace xor_crypto = analysis::crypto::xor_cipher;

void run_challenge_6() {
  std::cout << "Running Challenge 6..." << std::endl;

  std::string binary_data =
      base64::decode(file_io::read_file_as_string("data/challenge6_input.txt"));

  std::optional<std::string> key =
      xor_crypto::auto_detect_repeated_xor_recover_key(binary_data, 2, 40,
                                                       150.0);

  assert(key.has_value() && "Challenge 6 failed: No key found!");
  assert(key.value() == "Terminator X: Bring the noise" &&
         "Challenge 6 failed: Decoded key did not match the expected result!");

  std::cout << "Challenge 6 successful!" << std::endl;
}
