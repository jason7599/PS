#include <iostream>

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL); std::cin.tie(NULL);

    int n,m;
    std::cin>>n>>m;

    int *arr = new int[n+1];
    arr[0]=0;

    for(int i=1; i<=n; i++) {
        std::cin>>arr[i];
        arr[i]+=arr[i-1];
    }
    
    int x,y;
    for(int i=0; i<m; i++) {
        std::cin>>x>>y;
        std::cout<<arr[y]-arr[x-1]<<std::endl;
    }
}