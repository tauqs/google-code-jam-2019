#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	string s;
	int n;
	for(int t=0; t<T; t++){
		cin>>n;
		cin>>s;
		for(int i=0; i<s.length(); i++){
			if(s[i] =='E'){
				s[i] = 'S';
			}
			else{
				s[i] = 'E';
			}
		}
		cout<<"Case #"<<(t+1)<<": "<<s<<endl;
		
	}
	return 0;
}
