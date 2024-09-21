#include<bits/stdc++.h>
using namespace std;
//TT ktra gcd(e, phi n) = 1 
int gcd(int a, int b) {	
	if(b == 0 )
		return a;
	if(a % b == 0)
		return b;
	return gcd(b, a % b);
}
int soNguyenTo(int n)
{
    if (n < 2)    
        return 0;
	if(n == 2)
		return 1;
    for (int i = 2; i <= sqrt((float)n); i ++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
//Ham radom sinh e
int random(int minN, int maxN){
 return minN + rand() % (maxN + 1 - minN);
}
int sinh_e(int phi_n){
	int e = 0;
	srand((int)time(0));
	do {
		e = random(2, phi_n - 1);
	} while (gcd(e, phi_n) != 1);
	return e;
}
//Tinh nghich dao d = e^-1 mod n
long modInverse(long a, long n) {
	if(gcd(a, n) != 1)
		return 0;
	else {
		int r[50], q[50], x[50], y[50];	
		r[0] = n; 
		r[1] = a;				
		x[0] = 0; 
		x[1] = 1;
		y[0] = 1; 
		y[1] = 0;	 
		int i = 1;
		while (r[i] > 1) {
			r[i+1] = r[i-1] % r[i];
			q[i+1] = r[i-1] / r[i];
			x[i+1] = x[i-1] - q[i+1] * x[i];
			y[i+1] = y[i-1] - q[i+1] * y[i];
			i++;
		}		
		if(x[i] < 0){
			x[i] += n;
		}	
		return x[i];
	}	
}
//Ham mod sai
long mod(int a, int b, int n) {
	int temp[1000];
	int k = 0; 
	
    while (b > 0) {  
        // storing remainder in binary array 
        temp[k] = b % 2; 
        b = b / 2; 
        k++; 
    } 
  //  int index = 0;
//	for(int j = k - 1; j >= 0; j--){
//    	cout<<temp[j]<<endl;
//	}   
    int f = 1;   
    for(int i = k-1; i >= 0; i--) {
    	f = (f * f) % n;
    	if(temp[i] == 1)
    		f = (f * a) % n;
	}
	//if(f < 0) 
	//	f += n;
    return f;
}
int main() {
	int p, q;
	//m la ban ro de cho
	//sinh p, q
	srand((int)time(0));
	do {
		p = random(10, 1000);
		q = random(10, 1000);
	} while (!soNguyenTo(p) || !soNguyenTo(q));
	
	cout<<"q = "<<q<<endl;
	cout<<"p = "<<p<<endl;
	
	int n = p * q;
	int phi_n = (p - 1) * (q - 1);
	
	cout<<"n = "<<n<<endl;
	cout<<"phi_n = "<<phi_n<<endl;	
	//sinh e
//	int e = sinh_e(phi_n);
	int e = 2;
	while(e < phi_n) {
		if(gcd(e, phi_n) == 1)
			break;
		e++;
	}
	cout<<"e = "<< e <<endl;	
//	int e = random(2, phi_n - 1);
	//Luc sinh e da kiem tra gcd(e, phi_n) = 1, thuat toan tinh khong can kiem tra	
	int d = modInverse(e, phi_n);
	cout<<"d = "<<d<<endl;
	
	int m = 151;
	cout<<"m = "<<m<<endl;
	//Ma hoa 
	int c = mod(m, e, n);
	cout<<"Ban ma: c = "<<c<<endl;
	
	//Giai ma
	int giaima = mod(c, d, n);
	cout<<"Ban ro: m = "<<giaima<<endl;
	
}
