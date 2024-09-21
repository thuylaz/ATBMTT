#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

// Hàm tính a^b mod p
int power(int a, int b, int p) {
    int res = 1;

    while (b > 0) {
        if (b & 1) {
            res = (res * a) % p;
        }

        a = (a * a) % p;
        b >>= 1;
    }

    return res;
}

// Hàm ki?m tra tính nguyên t? c?a m?t s?
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

// Hàm tìm s? nguyên t? d?u tiên l?n hon ho?c b?ng n
int nextPrime(int n) {
    while (!isPrime(n)) {
        n++;
    }

    return n;
}

// Hàm t?o khóa bí m?t ng?u nhiên
int generateSecretKey(int p) {
    return 2 + rand() % (p - 2);
}

// Hàm t?o khóa công khai
int generatePublicKey(int g, int a, int p) {
    return power(g, a, p);
}

// Hàm tính khóa chung
int generateSharedKey(int publicKey, int secretKey, int p) {
    return power(publicKey, secretKey, p);
}

int main() {
    srand(time(NULL));

    cout << "CHUONG TRINH THUC HIEN THUAT TOAN DIFFIE-HELLMAN\n";
    cout << "=============================================\n";
    cout << "1. Tinh khoa cong khai\n";
    cout << "2. Tinh khoa chung\n";
    cout << "3. Thoat\n";

    int choice;
    cout << "Nhap lua chon cua ban (1/2/3): ";
    cin >> choice;

    if (choice != 1 && choice != 2) {
        return 0;
    }

    cout << "Nhap modulo p (so nguyen to): ";
    int p;
    cin >> p;

    if (!isPrime(p)) {
        cout << "Nhap sai modulo p. Vui long nhap lai.\n";
        return 0;
    }

    cout << "Nhap co so g (1 < g < p): ";
    int g;
    cin >> g;

    if (g <= 1 || g >= p) {
        cout << "Nhap sai co so g. Vui long nhap lai.\n";
        return 0;
    }

    if (choice == 1) {
        // Tính khoá công khai
        cout << "Nhap khoa bi mat a: ";
        int a;
        cin >> a;

        int publicKey = generatePublicKey(g, a, p);
        cout << "Khoa cong khai cua ban la: " << publicKey << endl;
    } else {
        // Tính khóa chung
        int a = generateSecretKey(p);
        int b = generateSecretKey(p);

        int A = generatePublicKey(g, a, p);
        int B = generatePublicKey(g, b, p);

        int sharedKeyA = generateSharedKey(B, a, p);
        int sharedKeyB = generateSharedKey(A, b, p);

        if (sharedKeyA == sharedKeyB) {
            cout << "Khoa chung cua ban la: " << sharedKeyA << endl;
        } else {
            cout << "Khong tao thanh khoa chung.\n";
        }
    }

    return 0;
}
