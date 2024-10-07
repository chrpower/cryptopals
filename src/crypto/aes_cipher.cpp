#include "aes_cipher.h"

#include <cassert>
#include <openssl/aes.h>
#include <openssl/evp.h>

namespace crypto::aes_cipher {
namespace decryption {

std::vector<unsigned char>
aes_128_ecb_decrypt(const std::vector<unsigned char> &ciphertext,
                    const std::vector<unsigned char> &key) {
  assert(key.size() == 16 && "Key must be 16 bytes for AES-128");

  EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
  std::vector<unsigned char> plaintext(ciphertext.size());

  // Initialize the decryption operation with AES-128-ECB
  EVP_DecryptInit_ex(ctx, EVP_aes_128_ecb(), NULL, key.data(), NULL);

  int len = 0;
  int plaintext_len = 0;
  // Perform decryption
  EVP_DecryptUpdate(ctx, plaintext.data(), &len, ciphertext.data(),
                    ciphertext.size());
  plaintext_len = len;

  // Finalize decryption
  EVP_DecryptFinal_ex(ctx, plaintext.data() + len, &len);
  plaintext_len += len;

  // Clean up
  EVP_CIPHER_CTX_free(ctx);

  plaintext.resize(plaintext_len);
  return plaintext;
}

} // namespace decryption
} // namespace crypto::aes_cipher
