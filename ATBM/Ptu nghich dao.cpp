// Tim phan tu nghich dao
#include <iostream>
using namespace std;

int extendedEuclidean(int a, int b, int& x, int& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int gcd = extendedEuclidean(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}

int modInverse(int a, int n) {
    int x, y;
    int gcd = extendedEuclidean(a, n, x, y);

    if (gcd != 1) {
        cout << "Khong ton tai nghich dao modulo." << endl;
        return -1;
    }

    // Đảm bảo x thuộc đoạn [0, n-1]
    x = (x % n + n) % n;

    return x;
}

int main() {
    int a, n;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap n: ";
    cin >> n;

    int result = modInverse(a, n);

    if (result != -1)
        cout << "Gia tri a mu -1 mod n la: " << result << endl;

    return 0;
} 


