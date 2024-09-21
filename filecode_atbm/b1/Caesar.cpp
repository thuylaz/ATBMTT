#include<bits/stdc++.h>

using namespace std;

string encrypt(string text, int key) {
    string result = "";
    // traverse text
    for (int i = 0; i < text.length(); i++) {
        // apply transformation to each character
        // Encrypt Uppercase letters
        if (isupper(text[i]))
            result += char((int(text[i]) + key - 65) % 26 + 65);
        // Encrypt Lowercase letters
        else
            result += char((int(text[i]) + key - 97) % 26 + 97);
    }
 
    // Return the resulting string
    return result;
}
 
string decrypt(string text, int key) {
	string result = "";
    // traverse text
    for (int i = 0; i < text.length(); i++) {
        // apply transformation to each character
        // Encrypt Uppercase letters
        if (isupper(text[i]))
            result += char(int(text[i] - key - 65+26) % 26 + 65);
        // Encrypt Lowercase letters
        else
            result += char(int(text[i] - key - 97+26) % 26 + 97);
    }
 
    // Return the resulting string
    return result;
	
}

int main()
{
  string text = "thuy";
    
    int key = 3;
    cout << "Text: " << text;
    cout << "\nKey: " << key;
    cout << "\nCipher: " << encrypt(text, key);
    cout << "\nPlaintextr:  " << decrypt(encrypt(text, key), key);
    
    return 0;
}
