#include <iostream>
#include <string>

using namespace std;

// H�m m? h�a chu?i b?n r? theo h? m?t Vigenere
string encryptVigenere(const string& plaintext, const string& key) {
    string ciphertext = "";
    int n = plaintext.length();
    int m = key.length();

    for (int i = 0; i < n; i++) {
        char c = plaintext[i];
        char keyChar = key[i % m];

        // Ki?m tra xem k? t? c� n?m trong kho?ng [A-Z] hay [a-z] kh�ng
        if (isalpha(c)) {
            // Chuy?n �?i k? t? v� k? t? kh�a th�nh s? nguy�n t��ng ?ng trong b?ng m? ASCII
            int cNumber = toupper(c) - 'A';
            int keyNumber = toupper(keyChar) - 'A';

            // M? h�a k? t? b?ng c�ch c?ng s? nguy�n c?a k? t? v?i s? nguy�n c?a k? t? kh�a
            int ciphertextNumber = (cNumber + keyNumber) % 26;

            // Chuy?n �?i s? nguy�n th�nh k? t? t��ng ?ng trong b?ng m? ASCII
            char ciphertextChar = ciphertextNumber + 'A';

            // Ki?m tra tr�?ng h?p c?a k? t? ban �?u �? ��a ra k? t? m? h�a ��ng
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

// H�m gi?i m? chu?i b?n m? theo h? m?t Vigenere
string decryptVigenere(const string& ciphertext, const string& key) {
    string plaintext = "";
    int n = ciphertext.length();
    int m = key.length();

    for (int i = 0; i < n; i++) {
        char c = ciphertext[i];
        char keyChar = key[i % m];

        // Ki?m tra xem k? t? c� n?m trong kho?ng [A-Z] hay [a-z] kh�ng
        if (isalpha(c)) {
            // Chuy?n �?i k? t? v� k? t? kh�a th�nh s? nguy�n t��ng ?ng trong b?ng m? ASCII
            int cNumber = toupper(c) - 'A';
            int keyNumber = toupper(keyChar) - 'A';

            // Gi?i m? k? t? b?ng c�ch tr? s? nguy�n c?a k? t? v?i s? nguy�n c?a k? t? kh�a
            int plaintextNumber = (cNumber - keyNumber + 26) % 26;

            // Chuy?n �?i s? nguy�n th�nh k? t? t��ng ?ng trong b?ng m? ASCII
            char plaintextChar = plaintextNumber + 'A';

            // Ki?m tra tr�?ng h?p c?a k? t? ban �?u �? ��a ra k? t? gi?i m? ��ng
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

    // Ki?m tra kh�a c� h?p l? kh�ng
    for (int i = 0; i < key.length(); ++i) {
        char c = key[i];
        if (!isalpha(c)) {
            cout << "Khoa khong hop le. Vui long nhap lai.\n";
            return 0;
        }
    }

    cin.ignore(); // X�a b? �?m nh?p �? c� th? nh?p chu?i

    string plaintext;
    cout << "Nhap chuoi ban ro: ";
    getline(cin, plaintext);

    // M? h�a chu?i b?n r?
    string ciphertext = encryptVigenere(plaintext, key);
    cout << "Chuoi ban ma: " << ciphertext << endl;

    // Gi?i m? chu?i b?n m?
    string decryptedText = decryptVigenere(ciphertext, key);
    cout << "Chuoi ban ro: " << decryptedText << endl;

    return 0;
}

