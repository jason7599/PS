#include <iostream>
#include <queue>

using namespace std;

bool trustGraph[10001][10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,m; cin>>n>>m;
    
    for(int i=0; i<m; i++) {
        int x , y;
        cin>> x >> y;
        trustGraph[x][y]=true;
        trustGraph[y][x]=true;
    }

    for(int i=1; i<=n; i++) {
        
    }

}