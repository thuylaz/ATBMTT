#include<bits/stdc++.h>
using namespace std;

int powerMod(int a, int b, int n) {
    int result = 1;
    a = a % n;

    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % n;
        a = (a * a) % n;
        b /= 2;
    }

    return result;
}

int main() {
    int a, b, n;
    cout << "Nhập giá trị a: ";
    cin >> a;
    cout << "Nhập giá trị b: ";
    cin >> b;
    cout << "Nhập giá trị n: ";
    cin >> n;

    int result = powerMod(a, b, n);
    cout << "Kết quả: " << result << endl;

    return 0;
}