#include <iostream>

using namespace std;

int coins[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,k; cin>>n>>k;

    for(int i=0; i<n; i++)
        cin>>coins[i];

    int count=0;

    for(int i=n-1; i>=0; i--) {
        if(coins[i]<=k) {
            count+=k/coins[i];
            k%=coins[i];
            if(!k) break;
        }
    }

    cout<<count;
}