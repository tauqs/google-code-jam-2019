#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main() {
    
    int T;
    cin>>T;

    for(int t=1; t<=T; t++)
    {
        ll n,k;
        cin>>n>>k;
        ll ans = 0;

        vector<ll> C(n, 0);
        vector<ll> D(n, 0);

        ll c;
        cin>>c;
        C[0] = c;
        for(int i=1; i<n; i++){
            cin>>c;
            //C[i] = max(C[i-1], c);
            C[i] = c;
        }

        cin>>c;
        D[0] = c;
        for(int i=1; i<n; i++){
            cin>>c;
            //D[i] = max(D[i-1], c);
            D[i] = c;
        }

        for(int i=0; i<n; i++){
            ll mxc = C[i];
            ll mxd = D[i];
            for(int j=i; j<n; j++){
                mxc = max(C[j], mxc);
                mxd = max(D[j], mxd);
                if(abs(mxc - mxd) <=k) ans++;
            }
        }

        printf("Case #%d: %lld\n",t, ans);
    }
    return 0;
}