#include "challenge7.h"

#include <cassert>
#include <iostream>

#include "aes_cipher.h"
#include "base64.h"
#include "file_io.h"

void run_challenge_7() {
  std::cout << "Running Challenge 7..." << std::endl;

  std::string binary_data =
      base64::decode(file_io::read_file_as_string("data/challenge7_input.txt"));

  std::string key_str = "YELLOW SUBMARINE";
  std::vector<unsigned char> key(key_str.begin(), key_str.end());
  std::vector<unsigned char> ciphertext(binary_data.begin(), binary_data.end());
  std::vector<unsigned char> plaintext =
      crypto::aes_cipher::decryption::aes_128_ecb_decrypt(ciphertext, key);

  std::string expected_start = "I'm back and I'm ringin' the bell";
  std::string plaintext_start(plaintext.begin(),
                              plaintext.begin() + expected_start.size());
  assert(plaintext_start == expected_start &&
         "First part of decryption is incorrect!");

  std::cout << "Challenge 7 successful!" << std::endl;
}