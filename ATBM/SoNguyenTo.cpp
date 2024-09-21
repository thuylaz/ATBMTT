//So nguyen to
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool SNT(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void RD(int a, int b, int& x, int& y) {
    
    srand(time(0));

    do {
        x = a + rand() % (b - a + 1);
    } while (!SNT(x));

    do {
        y = a + rand() % (b - a + 1);
    } while (!SNT(y) || y == x);
}

int main() {
    int a, b;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;

    int x, y;
    RD(a, b, x, y);

    cout << x << " " << y << endl;

    return 0;
}
