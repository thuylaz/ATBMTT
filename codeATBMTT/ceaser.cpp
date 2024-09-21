#include <iostream>
#include <string>

using namespace std;

string encrypt(string text, int shift)
{
    string result = "";
    for (int i = 0; i < text.length(); i++)
    {
        if (isalpha(text[i]))
        {
            char c = text[i];
            if (isupper(c))
            {
                c = char(int(c + shift - 65) % 26 + 65);
            }
            else
            {
                c = char(int(c + shift - 97) % 26 + 97);
            }
            result += c;
        }
        else
        {
            result += text[i];
        }
    }
    return result;
}

string decrypt(string text, int shift)
{
    return encrypt(text, 26 - shift);
}

int main()
{
    string text, result;
    int shift, choice;

    cout << "Enter your message: ";
    getline(cin, text);

    cout << "Enter the shift value: ";
    cin >> shift;

    do {
        cout << "Choose an option:" << endl;
        cout << "1. Ma hoa" << endl;
        cout << "2. Giai ma" << endl;
        cout << "3. Thoat" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                result = encrypt(text, shift);
                cout << "Van ban da ma hoa: " << result << endl;
                break;
            case 2:
                result = decrypt(text, shift);
                cout << "Van ban da giai ma:" << result << endl;
                break;
            case 3:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long thu lai." << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}
