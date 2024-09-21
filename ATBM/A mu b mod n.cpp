// A mu b mod n
#include <iostream>
using namespace std;

long long powerMod(long long a, long long b, long long n) {
    long long result = 1;
    a = a % n;

    while (b > 0) {
        if (b & 1)
            result = (result * a) % n;
        
        a = (a * a) % n;
        b >>= 1;
    }

    return result;
}

int main() {
    long long a, b, n;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
    cout << "Nhap n: ";
    cin >> n;

    long long result = powerMod(a, b, n);

    cout << "Gia tri a mu b mod n la: " << result << endl;

    return 0;
}
