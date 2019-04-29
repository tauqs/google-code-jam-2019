#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	long n,a,b,tx,x;
	for(int t=0; t<T; t++){
		cin>>n;
		a=0, b=0;
		tx = 1;
		while(n>0){
			x = n%10;
			n = n/10;
			if(x==4){
				a = a + 2*tx;
				b = b + 2*tx;
			}
			else{
				a  = a + x*tx;
			}
			tx*=10;
		}
		cout<<"Case #"<<(t+1)<<": "<<a<<" "<<b<<endl;
		
	}
	return 0;
}
