#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define ll long long

int main() {
    
    int T;
    cin>>T;

    int W;
    cin>>W;

    int r1,r2,r3,r4,r5,r6;

    for(int t=1; t<=T; t++)
    {
    	cout<<"200"<<endl;
    	ll num;
    	cin>>num;

    	ll t40 = pow(2,40);
    	ll t33 = pow(2,33);
    	ll t50 = pow(2,50);
    	r6 = (num % t40)/t33;

    	r5 = ((num - r6*t33) % t50)/t40;

    	r4 = (num - r6*t33 - r5*t40)/t50;

    	cout<<"50"<<endl;
    	cin>>num;

    	ll rhs = r4*pow(2,12) + r5*pow(2,10) + r6*pow(2,8);

    	ll t25 = pow(2,25);
    	ll t16 = pow(2,16);

    	r3 = ((num - rhs)%t25)/t16;
    	r2 = ((num - r3*t16)%t50)/t25;
    	r1 = ((num - r3*t16 - r2*t25)/t50);
    	cout<<r1<<" "<<r2<<" "<<r3<<" "<<r4<<" "<<r5<<" "<<r6<<endl;

    	int result;
    	cin>>result;
    	if(result==-1) break;
    }
    return 0;
}