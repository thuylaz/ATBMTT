#include<bits/stdc++.h>
using namespace std;

int UCLN(int a, int b){
	int r;
	while(true){
		if(b==0){
			return a;
		}
		r=a%b;
		a=b;
		b=r;
	}
}
int eclid(int r[], int q[], int x[], int y[]){
	
	int i = 0;
	while(r[i]!=0){
		i++;
		r[i]=r[i-2]%r[i-1];
		q[i]=r[i-2]/r[i-1];
		x[i]=x[i-2]-q[i]*x[i-1];
		y[i]=y[i-2]-q[i]*y[i-1];
	}
	return x[i-1];
}
int main(){
	int r[100],q[100],x[100], y[100];
	x[-1]=0;
	x[0]=1;
	y[-1]=0;
	y[0]=1;
	r[-1]=1759;
	r[0]=550;
	if(UCLN(r[0],r[-1])==1){
		cout<<eclid(r,q,x,y);
	}else{
		cout<<"Hai so khong phai so nguyen to cung nhau";
	}
		
}