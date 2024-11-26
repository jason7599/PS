#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int l, p, v;

    for(int i=1; ;i++) {
        cin>>l>>p>>v;
        if(!l && !p && !v) break;
        cout<<"Case "<<i<<": "<<(v / p) * l + min(v % p, l) << '\n';
    }

    
}