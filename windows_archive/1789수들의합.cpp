#include <iostream>

using namespace std;

int main() {
    int n; cin>>n;
    int res = 0;
    for(int i=1 ; ; i++) {
        res++;
        if(n - i <= i) break;
        n -= i;
    }
    cout<<res;
}