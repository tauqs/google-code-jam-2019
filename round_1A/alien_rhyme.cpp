#include <iostream>
#include <vector>
using namespace std;

int max_pairs(vector<vector<int> > &dic, vector<vector<vector<bool> > > &pairs,vector<bool> &taken, int index){
    if(index>=26) return 0;
    int m = dic[index].size();
    //int ans = 2;
    int mx = 0;
    for(int i=0; i<m; i++){
        int a = dic[index][i];
        if(taken[a]) continue;
        taken[a] = true;
        for(int j=i+1; j<m; j++){
            int b = dic[index][j];
            if(taken[b]) continue;
            if(!pairs[a][b][index]) continue;
            taken[b] = true;
            mx = max(mx, 2+max_pairs(dic, pairs, taken, index+1));
            taken[b] = false;
        }
        taken[a] = false;
    }
    mx = max(mx, max_pairs(dic, pairs, taken, index+1));
    return (mx);
}

int main() {
    
    int T;
    cin>>T;
    
    int n;
    for(int t=1; t<=T; t++)
    {
        cin>>n;
        vector<vector<int> > dic(26, vector<int> ());
        vector<string> strs;
        vector<vector<vector<bool> > > pairs(n, vector<vector<bool> >(n, vector<bool> (26, false))); 
        for(int i=0; i<n; i++){
            string s;
            cin>>s;
            strs.push_back(s);
            for(int j=0; j<s.length(); j++){
                dic[(s[j]-65)].push_back(i); 
            }
        }

        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         int it = 0;
        //         int a = strs[i].length();
        //         int b = strs[j].length();
        //         int l = min(a,b);
        //         while(it<l){
        //             if(strs[i][a-it-1] == strs[j][b-it-1]){
        //                 pairs[i][j][(strs[i][a-it-1]- 65)] = true;
        //             }
        //             else break;
        //             it++;
        //         }
        //     }
        // }

        vector<bool> taken(n, false);
        //cout<<pairs[0][0][0]<<"*"<<endl;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<" ";
                for(int k=0; k<26; k++){
                    cout<<pairs[i][j][k]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
        int ans = max_pairs(dic,pairs, taken, 0);
        printf("Case #%d: %d\n",t, ans);
    }
    return 0;
}