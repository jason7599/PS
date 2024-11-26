#include <iostream>

using namespace std;

int n, s;
int arr[20];
int ans;

void brute(int currentSum=0, int index=0, bool changed=false) {
    if(currentSum == s && changed) ans++;
    if(index==n) return;

    brute(currentSum, index+1, false);
    brute(currentSum+arr[index], index+1, true);
}

int main() {

    cin>>n>>s;

    for(int i=0; i<n; i++)
        cin>>arr[i];

    brute();

    cout<<ans;
}