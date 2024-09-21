#include<bits/stdc++.h>
using namespace std;

int UCLN(int a, int b)
{
	if(b == 0)
		return a;
	else 
	 	return UCLN(b,a%b);
}
int ND(int a, int b)
{
	int r[100], q[100], x[100], y[100];
	r[0] = a, r[1] = b;
	x[0] = 1, y[0] = 0;
	x[1] = 0, y[1] =1;
	r[2] = r[0] % r[1];
	int i = 2;
	while (r[i-1] != 1)
	{
		r[i] = r[i-2] % r[i-1];
		q[i] = r[i-2] / r[i-1];
		x[i] = x[i-2] - q[i] * x[i-1];
		y[i] = y[i-2] - q[i] * y[i-1];
		i++;
	}
	if(x[i-1] < 0 ) x[i-1] =x[i-1] + b;
	return x[i-1];
}
bool KTNT(int n)
{
	if(n==2) return true;
	for(int i=2; i<=sqrt(n); i++)
	{
		if(n%i ==0) return false;
	}
	return true;
}
void SSNT(int n )
{
	bool kt = false;
	while (KTNT(n)!= true)
	{
		n++;	
	}
	cout<< n;
}
string NP(int n)
{
	int r;
	string d;
	do {
		if(n%2 == 0)
		{
			d = "0"+d; 
		} else {
			d = "1" +d;
		}
		n = n/2;
	} while (n>0);
	return d;
}
int MOD (int a, int b , int n)
{
	int f = 1; 
	string bit = NP(b);
	for(int i=0; i<bit.size(); i++)
	{
		f = (f*f)%n;
		if(bit[i] == '1')
			f = (f*a)%n;
	}
	return f;
}
string CaesarMH(string p, int k)
{
	int ma;
	string c;
	for (int i=0; i<p.size(); i++)
	{
		ma = (int) ((p[i]-65 +k) % 26);
		if(ma <0) ma = ma+26;
		c = c +(char) (ma+65);
	}
	return c;
}
string CaesarGM(string p, int k)
{
	int ma;
	string c;
	for (int i=0; i<p.size(); i++)
	{
		ma = (int) ((p[i]-65 -k) % 26);
		if(ma <0) ma = ma+26;
		c = c +(char) (ma+65);
	}
	return c;
}
string AffineMH(string p, int a, int b)
{
	int x, E;
	string C;
	for(int i=0; i<p.size(); i++)
	{
		x = (int) (p[i] - 65);
		E = (a*x +b)%26;
		if(E<0) 
		{
			E = E +26;
			C = C +(char)(E+65);
		}
	}
	return p;
}
int main()
{
	int a = 550; int b = 1759; int n=220;
	cout<<"ND: "<<ND(550,1759)<<endl;
	cout<<"UCLN: "<<UCLN(550, 1759)<<endl;
	cout<<"SSNT: ";
	SSNT(n);
	cout<<endl<<"MOD:"<<MOD(11,48,23)<<endl;
	cout<<"Caeser ma hoa: " <<CaesarMH("ABCD", -1)<<endl;
	cout<<"Caeser giai ma: "<<CaesarGM(CaesarMH("ABCD",-1),-1)<<endl;
	return 0;
}