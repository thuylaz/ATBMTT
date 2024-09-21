#include <iostream>
using namespace std;
// Ma Affine
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

string encrypt(string text, int a, int b) {
    string ciphertext = "";
    int n = 26; 

    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];

        if (isalpha(ch)) {
            if (isupper(ch))
                ch = ((a * (ch - 'A') + b) % n) + 'A';
            else
                ch = ((a * (ch - 'a') + b) % n) + 'a';
        }

        ciphertext += ch;
    }

    return ciphertext;
}

string decrypt(string ciphertext, int a, int b) {
    string text = "";
    int n = 26;

    int aInverse = modInverse(a, n);

    for (int i = 0; i < ciphertext.length(); i++) {
        char ch = ciphertext[i];

        if (isalpha(ch)) {
            if (isupper(ch))
                ch = (aInverse * ((ch - 'A' - b + n) % n)) + 'A';
            else
                ch = (aInverse * ((ch - 'a' - b + n) % n)) + 'a';
        }

        text += ch;
    }

    return text;
}

int main() {
    string message;
    int a, b;

    cout << "Nhap chuoi can ma hoa: ";
    getline(cin, message);

    cout << "Nhap gia tri a: ";
    cin >> a;

    cout << "Nhap gia tri b: ";
    cin >> b;

    if (gcd(a, 26) != 1) {
        cout << "Gia tri a khong hop le. Vui long chon gia tri khac." << endl;
        return 0;
    }

    string encryptedMessage = encrypt(message, a, b);
    string decryptedMessage = decrypt(encryptedMessage, a, b);

    cout << "Chuoi da ma hoa: " << encryptedMessage << endl;
    cout << "Chuoi da giai ma: " << decryptedMessage << endl;

    return 0;
}
