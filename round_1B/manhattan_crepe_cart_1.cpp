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
        //int count = 0
        for(int j=0; j<p; j++){
                //if(i==j) continue;
                node person1 = people[j];
                int x1 = person1.x;
                int y1 = person1.y;
                char d1 = person1.d;

                if(x1> 0 && d1 == 'W') mx++;
        }

        for(int i=0; i<p; i++){
            node person = people[i];
            int x = person.x;
            int y = person.y;
            char d = person.d;
            int count = 0;

            if(d!='E') continue;

            for(int j=0; j<p; j++){
                //if(i==j) continue;
                node person1 = people[j];
                int x1 = person1.x;
                int y1 = person1.y;
                char d1 = person1.d;

                if(x1>x+1 && d1 == 'W') count++;
                if(x1<x+1 && d1 == 'E') count++;
            }


            if((count == mx && (x+1)<X) || count > mx){
                X = x + 1;
                mx = count;
            }
        }

        mx = 0;

        for(int j=0; j<p; j++){
                //if(i==j) continue;
                node person1 = people[j];
                int x1 = person1.x;
                int y1 = person1.y;
                char d1 = person1.d;

                if(y1> 0 && d1 == 'S') mx++;
        }

        for(int i=0; i<p; i++){
            node person = people[i];
            int x = person.x;
            int y = person.y;
            char d = person.d;
            int count = 0;

            if(d!='N') continue;

            for(int j=0; j<p; j++){
                //if(i==j) continue;
                node person1 = people[j];
                int x1 = person1.x;
                int y1 = person1.y;
                char d1 = person1.d;

                if(y1>y+1 && d1 == 'S') count++;
                if(y1<y+1 && d1 == 'N') count++;
            }


            if((count == mx && (y+1)<Y) || count > mx){
                Y = y + 1;
                mx = count;
            }
        }


        printf("Case #%d: %d %d\n",t, X, Y);
    }
    return 0;
}