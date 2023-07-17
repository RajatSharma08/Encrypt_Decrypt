// Encryption and Decryption functions
#include <iostream>
#include <string>

std::string encrypt(const std::string& message, int shift) {
    std::string result = "";
    for (char c : message) {
        if (isalpha(c)) {
            char encrypted = (c + shift - 'a') % 26 + 'a';
            result += encrypted;
        } else {
            result += c;
        }
    }
    return result;
}

std::string decrypt(const std::string& encryptedMessage, int shift) {
    std::string result = "";
    for (char c : encryptedMessage) {
        if (isalpha(c)) {
            char decrypted = (c - shift - 'a' + 26) % 26 + 'a';
            result += decrypted;
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    std::string message = "Hello, World!";
    int shift = 5;
    std::string encryptedMessage = encrypt(message, shift);
    std::string decryptedMessage = decrypt(encryptedMessage, shift);
    std::cout << "Encrypted Message: " << encryptedMessage << std::endl;
    std::cout << "Decrypted Message: " << decryptedMessage << std::endl;
    return 0;
}
