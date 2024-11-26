#include <iostream>

using namespace std;

int tiling[1001];

int main() {
    tiling[1] = 1;
    tiling[2] = 2;

    int n; cin>>n;

    for(int i=3; i<=n; i++)
        tiling[i] =(tiling[i-1] + tiling[i-2])%10007;

    cout<<tiling[n];
}
