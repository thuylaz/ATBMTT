#include <iostream>
#include <cstring>
#include <bits/stdc++.h>

void encrypt_message(const unsigned char* message, int message_length, const unsigned char* key, unsigned char* encrypted_message) {
    DES_cblock des_key;
    DES_key_schedule key_schedule;

    memcpy(des_key, key, sizeof(DES_cblock));

    DES_set_key_unchecked(&des_key, &key_schedule);

    for (int i = 0; i < message_length; i += 8) {
        DES_ecb_encrypt((DES_cblock*)(message + i), (DES_cblock*)(encrypted_message + i), &key_schedule, DES_ENCRYPT);
    }
}

void decrypt_message(const unsigned char* encrypted_message, int message_length, const unsigned char* key, unsigned char* decrypted_message) {
    DES_cblock des_key;
    DES_key_schedule key_schedule;

    memcpy(des_key, key, sizeof(DES_cblock));

    DES_set_key_unchecked(&des_key, &key_schedule);

    for (int i = 0; i < message_length; i += 8) {
        DES_ecb_encrypt((DES_cblock*)(encrypted_message + i), (DES_cblock*)(decrypted_message + i), &key_schedule, DES_DECRYPT);
    }
}

int main() {
    const unsigned char message[] = "Hello, DES!";
    const unsigned char key[] = "01234567";
    const int message_length = strlen((const char*)message);

    int padded_length = ((message_length + 7) / 8) * 8;
    unsigned char* padded_message = new unsigned char[padded_length];
    memcpy(padded_message, message, message_length);
    memset(padded_message + message_length, 0, padded_length - message_length);

    unsigned char encrypted_message[padded_length];
    unsigned char decrypted_message[padded_length];

    encrypt_message(padded_message, padded_length, key, encrypted_message);
    decrypt_message(encrypted_message, padded_length, key, decrypted_message);

    std::cout << "Original message: " << message << std::endl;
    std::cout << "Encrypted message: " << encrypted_message << std::endl;
    std::cout << "Decrypted message: " << decrypted_message << std::endl;

    delete[] padded_message;

    return 0;
}
