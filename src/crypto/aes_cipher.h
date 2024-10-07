#ifndef AES_CIPHER_H
#define AES_CIPHER_H

#include <string>
#include <vector>

// Namespace for AES-related operations
namespace crypto::aes_cipher {

// Namespace for AES decryption operations
namespace decryption {

// Performs AES-128 decryption in ECB mode.
// Takes in ciphertext as binary data and a 16-byte key.
// Returns the decrypted plaintext.
std::vector<unsigned char>
aes_128_ecb_decrypt(const std::vector<unsigned char> &ciphertext,
                    const std::vector<unsigned char> &key);

} // namespace decryption

} // namespace crypto::aes_cipher

#endif // AES_CIPHER_H
