#include <iostream>
#include <queue>

using namespace std;

bool land[50][50];
bool visited[50][50];

int main() {

    while(true) {
        int n, m;
        cin>>n>>m;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int temp; cin>>temp;
                land[i][j] = (temp==1);
            }
        }

        int islandCnt = 0;
        for(int x=0; x<m; x++) {
            for(int y=0; y<n; y++) {
                
            }
        }
    }
}