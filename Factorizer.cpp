#include <iostream>

using namespace std;



int f(int x,int n)
{
	return (x*x+1)%n;
}
int abs(int x)
{
	if(x<0)
		x=-x;
	return x;
}
int gcd(int a, int b)
{
		if(b%a==0)
			return a;
		else
			gcd(b%a,a);
}

void go_Pollards_rho_algo(int n)
{
	int x=2, y=2, d=1;
	cout<<"n="<<n<<endl;
	if(n==1)
		return;
	while(d==1){
		x = f(x,n);
		y = f(f(y,n),n);
		d = gcd(abs(x-y),n);
		cout<<"x="<<x<<" y="<<y<<" d="<<d<<endl;
	}	
	go_Pollards_rho_algo(n/d);
}
int main(){

	go_Pollards_rho_algo(8051);
}
