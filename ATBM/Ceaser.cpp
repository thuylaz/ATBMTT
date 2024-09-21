#include <iostream>
using namespace std;
// Ma Ceaser
string encrypt(string text, int n) {
    string ciphertext = "";

    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];

        if (isalpha(ch)) {
            if (isupper(ch))
                ch = (ch - 'A' + n) % 26 + 'A';
            else
                ch = (ch - 'a' + n) % 26 + 'a';
        }

        ciphertext += ch;
    }

    return ciphertext;
}

string decrypt(string ciphertext, int n) {
    string text = "";

    for (int i = 0; i < ciphertext.length(); i++) {
        char ch = ciphertext[i];
		//kiem tra ki tu trong bang chu cai alphabet
        if (isalpha(ch)) {
            if (isupper(ch))
                ch = (ch - 'A' - n + 26) % 26 + 'A';
            else
                ch = (ch - 'a' - n + 26) % 26 + 'a';
        }

        text += ch;
    }

    return text;
}

int main() {
    string message;
    int shift;

    cout << "Nhap chuoi can ma hoa: ";
    getline(cin, message);

    cout << "Nhap khoa K: ";
    cin >> shift;

    string encryptedMessage = encrypt(message, shift);
    string decryptedMessage = decrypt(encryptedMessage, shift);

    cout << "Chuoi da ma hoa: " << encryptedMessage << endl;
    cout << "Chuoi da giai ma: " << decryptedMessage << endl;

    return 0;
}
