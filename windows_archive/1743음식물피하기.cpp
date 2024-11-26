#include <iostream>
#include <queue>

using namespace std;

int sizeX, sizeY;
bool trash[101][101];
bool visited[101][101];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main() {
    int k;
    cin>>sizeX>>sizeY>>k;

    for(int i=0; i<k; i++) {
        int x, y; cin>>x>>y;
        trash[x][y] = true;
    }

    int biggestTrash = 0;
    for(int x=1; x<=sizeX; x++) {
        for(int y=1; y<=sizeY; y++) {
            if(!trash[x][y] || visited[x][y]) continue;

            queue<pair<int,int>> q;
            q.push({x,y}); 
            visited[x][y] = true;
            int size = 0;

            while(!q.empty()) {
                int xx = q.front().first;
                int yy = q.front().second;
                q.pop(); size++;
                for(int k=0; k<4; k++) {
                    int nx = xx + dx[k];
                    int ny = yy + dy[k];

                    if(!nx || nx>sizeX || !ny || ny>sizeY
                    || visited[nx][ny] || !trash[nx][ny]) continue;

                    q.push({nx,ny}); visited[nx][ny] = true;
                }
            }

            if(biggestTrash < size) biggestTrash = size;
        }
    }

    cout<<biggestTrash;
}