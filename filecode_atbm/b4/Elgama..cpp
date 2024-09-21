#include <bits/stdc++.h>

using namespace std;

// ham tinh a^b mod p
long long power(long long a, long long b, long long p) {
    if (b == 1) return a % p;
    long long temp = power(a, b / 2, p);
    if (b % 2 == 0) return (temp * temp) % p;
    else return ((temp * temp) % p * a) % p;
}

// ham kiem tra so nguyen to
bool isPrime(long long n) {
    if (n <= 1) return false;
    for (long long i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    long long p, alpha, x, k;
    cout << "So nguyen to p: "; cin>>p;
    cout << "Alpha: " ; cin>>alpha;
    cout << "Khoa bi mat x (1 < x < p-1): "; cin>>x;
	long long y = power(alpha, x, p);
    cout << "Khoa cong khai y: " << y << endl;

    // ma hoa
    long long m; 
    cout << "Nhap m: ";
    cin >> m;
    cout << "Chon ngau nhien k (1 < k < p-1): "; cin>>k; 
    long long a = power(alpha, k, p);
    long long b = (m * power(y, k, p)) % p;

    cout << "Cap ma (a, b): (" << a << ", " << b << ")" << endl;

    // gia ma
    long long giaima = (b * power(a, p - 1 - x, p)) % p;
    cout << "Tin mat sau khi giai ma: " << giaima << endl;

    return 0;
}
