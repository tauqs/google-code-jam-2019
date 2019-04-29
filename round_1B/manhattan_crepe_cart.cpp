#include <iostream>
#include <vector>
using namespace std;

struct node{
    int x;
    int y;
    char d;

    node(){
        x = 0;
        y = 0;
        d = 'N';
    }

    node(int X, int Y, int D){
        x = X;
        y = Y;
        d = D;
    }
};

int possible(int x, int y, node person){
    int x1 = person.x;
    int y1 = person.y;
    char d = person.d;

    if(d == 'N' || d == 'S'){
        if(y < y1 && d == 'S') return 1;
        if(y > y1 && d == 'N') return 1;
    }
    else{
        if(x < x1 && d == 'W') return 1;
        if(x > x1 && d == 'E') return 1;
    }

    return 0;
}

int main() {
    
    int T;
    cin>>T;

    for(int t=1; t<=T; t++)
    {
        int p,q;
        cin>>p>>q;

        vector<node> people(p);

        for(int i=0; i<p; i++){
            int x,y;
            char d;
            cin>>x;
            cin>>y;
            cin>>d;

            node person = node(x, y, d);
            people[i] = person;
        }

        int mx = 0;
        int X = 0;
        int Y = 0;
        for(int i=0; i<=q; i++){
            for(int j=0; j<=q; j++){
                int count = 0;
                for(int k=0; k<p; k++){
                    count += possible(i, j, people[k]);
                }
                if(count>mx){
                    mx = count;
                    X = i;
                    Y = j;
                }
            }
        }


        printf("Case #%d: %d %d\n",t, X, Y);
    }
    return 0;
}