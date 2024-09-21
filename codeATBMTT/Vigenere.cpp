#include <iostream>
#include <string>

using namespace std;

// Hàm m? hóa chu?i b?n r? theo h? m?t Vigenere
string encryptVigenere(const string& plaintext, const string& key) {
    string ciphertext = "";
    int n = plaintext.length();
    int m = key.length();

    for (int i = 0; i < n; i++) {
        char c = plaintext[i];
        char keyChar = key[i % m];

        // Ki?m tra xem k? t? có n?m trong kho?ng [A-Z] hay [a-z] không
        if (isalpha(c)) {
            // Chuy?n ð?i k? t? và k? t? khóa thành s? nguyên týõng ?ng trong b?ng m? ASCII
            int cNumber = toupper(c) - 'A';
            int keyNumber = toupper(keyChar) - 'A';

            // M? hóa k? t? b?ng cách c?ng s? nguyên c?a k? t? v?i s? nguyên c?a k? t? khóa
            int ciphertextNumber = (cNumber + keyNumber) % 26;

            // Chuy?n ð?i s? nguyên thành k? t? týõng ?ng trong b?ng m? ASCII
            char ciphertextChar = ciphertextNumber + 'A';

            // Ki?m tra trý?ng h?p c?a k? t? ban ð?u ð? ðýa ra k? t? m? hóa ðúng
            if (islower(c)) {
                ciphertextChar = tolower(ciphertextChar);
            }

            ciphertext += ciphertextChar;
        } else {
            ciphertext += c;
        }
    }

    return ciphertext;
}

// Hàm gi?i m? chu?i b?n m? theo h? m?t Vigenere
string decryptVigenere(const string& ciphertext, const string& key) {
    string plaintext = "";
    int n = ciphertext.length();
    int m = key.length();

    for (int i = 0; i < n; i++) {
        char c = ciphertext[i];
        char keyChar = key[i % m];

        // Ki?m tra xem k? t? có n?m trong kho?ng [A-Z] hay [a-z] không
        if (isalpha(c)) {
            // Chuy?n ð?i k? t? và k? t? khóa thành s? nguyên týõng ?ng trong b?ng m? ASCII
            int cNumber = toupper(c) - 'A';
            int keyNumber = toupper(keyChar) - 'A';

            // Gi?i m? k? t? b?ng cách tr? s? nguyên c?a k? t? v?i s? nguyên c?a k? t? khóa
            int plaintextNumber = (cNumber - keyNumber + 26) % 26;

            // Chuy?n ð?i s? nguyên thành k? t? týõng ?ng trong b?ng m? ASCII
            char plaintextChar = plaintextNumber + 'A';

            // Ki?m tra trý?ng h?p c?a k? t? ban ð?u ð? ðýa ra k? t? gi?i m? ðúng
            if (islower(c)) {
                plaintextChar = tolower(plaintextChar);
            }

            plaintext += plaintextChar;
        } else {
            plaintext += c;
        }
    }

    return plaintext;
}

int main() {
    string key;
    cout << "Nhap khoa: ";
    cin >> key;

    // Ki?m tra khóa có h?p l? không
    for (int i = 0; i < key.length(); ++i) {
        char c = key[i];
        if (!isalpha(c)) {
            cout << "Khoa khong hop le. Vui long nhap lai.\n";
            return 0;
        }
    }

    cin.ignore(); // Xóa b? ð?m nh?p ð? có th? nh?p chu?i

    string plaintext;
    cout << "Nhap chuoi ban ro: ";
    getline(cin, plaintext);

    // M? hóa chu?i b?n r?
    string ciphertext = encryptVigenere(plaintext, key);
    cout << "Chuoi ban ma: " << ciphertext << endl;

    // Gi?i m? chu?i b?n m?
    string decryptedText = decryptVigenere(ciphertext, key);
    cout << "Chuoi ban ro: " << decryptedText << endl;

    return 0;
}

