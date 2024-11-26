#include <iostream>

using namespace std;

int p[11];

int func(int n) {
    if(p[n]) return p[n];
    int res = 0;
    for(int i=1; i<4; i++) {
        res+=func(n-i);
    }
    p[n] = res;
    return res;
}

int main() {
    p[1] = 1;
    p[2] = 2;
    p[3] = 4;

    int t; cin>>t;
    for(int i=0; i<t; i++) {
        int x; cin>>x;
        cout<<func(x)<<'\n';
    }
}