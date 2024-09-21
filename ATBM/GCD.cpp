// Tim GCD(a,b)
#include <bits/stdc++.h>
using namespace std;

void Nhap(int &a, int &b){
	cout << "Nhap a: ";
	cin >> a;
	cout << "Nhap b: ";
	cin >> b;
}

int GCD(int a, int b) {
	if (a == 0) return b;
	if (b == 0) return a;
	if (a > b)
		return GCD(b, a % b);
	else return GCD(a, b % a);
}

int main() {
	int a, b;
	Nhap(a, b);
	cout << GCD(a, b);
}
