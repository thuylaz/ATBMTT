#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Hàm tính GCD theo thu?t toán Euclid m? r?ng
int gcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

// Hàm tính ngh?ch d?o nguyên modulo
int modInverse(int a, int m) {
    int x, y;
    int g = gcd(a, m, x, y);
    if (g != 1)
        return -1;
    return (x % m + m) % m;
}

// Hàm ki?m tra tính nguyên t? c?a s?
bool isPrime(int n, int k) {
    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;
    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;
    for (int i = 0; i < k; i++) {
        int a = 2 + rand() % (n - 4);
        long long x = pow(a, d);
        x = x % n;
        if (x == 1 || x == n - 1)
            continue;
        while (d != n - 1 && x != 1 && x != n - 1) {
            x = (x * x) % n;
            d *= 2;
        }
        if (x != n - 1)
            return false;
    }
    return true;
}

// Hàm sinh s? nguyên t?
int generatePrime(int lower, int upper) {
    int num = rand() % (upper - lower + 1) + lower;
    while (!isPrime(num, 5))
        num = rand() % (upper - lower + 1) + lower;
    return num;
}

// Hàm tính a^b mod m
int modExp(int a, int b, int m) {
    int res = 1;
    a = a % m;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        b >>= 1;
        a = (a * a) % m;
    }
    return res;
}

// Hàm mã hóa RSA
int encrypt(int message, int e, int n) {
    return modExp(message, e, n);
}

// Hàm gi?i mã RSA
int decrypt(int cipher, int d, int n) {
    return modExp(cipher, d, n);
}

int main() {
    srand(time(NULL));

    int p, q, n, phi_n, e, d, choice, message, cipher;

    cout << "CHUONG TRINH RSA\n";
    cout << "1. Ma hoa\n";
    cout << "2. Giai ma\n";
    cout << "Nhap lua chon cua ban (1-2): ";
    cin >> choice;

    if (choice == 1) {
        cout << "\n-- MA HOA RSA --\n";
        cout << "Nhap so nguyen to thu nhat (p): ";
        cin >> p;
        while (!isPrime(p, 5)) {
            cout << "p khong phai la so nguyen to. Nhap lai: ";
            cin >> p;
        }
        cout << "Nhap so nguyen to thu hai (q): ";
        cin >> q;
        while (!isPrime(q, 5)) {
            cout << "q khong phai la so nguyen to. Nhap lai: ";
            cin >> q;
        }
        n = p * q;
        phi_n = (p - 1) * (q - 1);
        e = generatePrime(2, phi_n - 1);
       while (gcd(e, phi_n, d, n) != 1)
            e = generatePrime(2, phi_n - 1);
        cout << "Khoa cong khai la: (" << e << ", " << n << ")\n";
        cout << "Khoa bi mat la: (" << d << ", " << n << ")\n";
        cout << "Nhap chuoi can ma hoa: ";
        cin >> message;
        cipher = encrypt(message, e, n);
        cout << "Chuoi da ma hoa: " << cipher << endl;
    }
    else if (choice == 2) {
        cout << "\n-- GIAI MA RSA --\n";
        cout << "Nhap khoa cong khai (e, n): ";
        cin >> e >> n;
        cout << "Nhap khoa bi mat (d, n): ";
        cin >> d >> n;
        cout << "Nhap chuoi da ma hoa: ";
        cin >> cipher;
        message = decrypt(cipher, d, n);
        cout << "Chuoi da giai ma: " << message << endl;
    }
    else {
        cout << "Lua chon khong hop le.\n";
        return 0;
    }

    return 0;
}
