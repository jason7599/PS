#include <iostream>
#include <queue>

using namespace std;

bool cabbage[50][50];
bool visited[50][50];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main() {

    int t; cin>>t;

    for(int _t=0; _t<t; _t++) {

        int sizeX, sizeY, cabbageCount;
        cin>>sizeX>>sizeY>>cabbageCount;

        if(_t) {
            for(int i=0; i<sizeX; i++) {
                for(int j=0; j<sizeY; j++) {
                    visited[i][j] = false;
                    cabbage[i][j] = false;
                }
            }
        }

        for(int i=0; i<cabbageCount; i++) {
            int x, y; cin>>x>>y;
            cabbage[x][y] = true;
        }

        int wormsNeeded = 0;
        for(int i=0; i<sizeX; i++) {
            for(int j=0; j<sizeY; j++) {
                if(visited[i][j] || !cabbage[i][j]) continue;
                queue<pair<int,int>> q; q.push({i,j});
                wormsNeeded++; visited[i][j] = true;

                while(!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second; q.pop();
                    for(int k=0; k<4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(nx<0 || nx==sizeX || ny<0 || ny==sizeY) continue;
                        if(visited[nx][ny] || !cabbage[nx][ny]) continue;
                        q.push({nx,ny}); visited[nx][ny] = true;
                    }
                }
            }
        }
        cout<<wormsNeeded<<'\n';
    }

}