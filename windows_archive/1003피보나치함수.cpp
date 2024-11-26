#include <iostream>

using namespace std;

int zeroCall[41];
int oneCall[41];

int main() {

    zeroCall[0] = 1; oneCall[0] = 0;
    zeroCall[1] = 0; oneCall[1] = 1;

    for(int i=2; i<41; i++) {
        zeroCall[i] = zeroCall[i-1] + zeroCall[i-2];
        oneCall[i] = oneCall[i-1] + oneCall[i-2];
    }

    int n; cin>>n;
    for(int i=0; i<n; i++) {
        int x; cin>>x;
        cout<<zeroCall[x]<<' '<<oneCall[x]<<'\n';
    }
}