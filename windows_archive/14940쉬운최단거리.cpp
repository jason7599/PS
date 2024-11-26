#include <iostream>
#include <queue>

using namespace std;

bool passable[1000][1000];
bool visited[1000][1000];
int dist[1000][1000];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main() {
    int sizeX, sizeY;
    cin>>sizeX>>sizeY;

    int goalX, goalY;
    for(int i=0; i<sizeX; i++) {
        for(int j=0; j<sizeY; j++) {
            int temp; cin>>temp;
            if(temp==2) {
                goalX = i;
                goalY = j;
            }
            else passable[i][j] = temp;
        }
    }

    queue<pair<int,int>> q;
    q.push({goalX, goalY});
    visited[goalX][goalY] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0; k<4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx<0 || nx==sizeX || ny<0 || ny==sizeY) continue;
            if(visited[nx][ny] || !passable[nx][ny]) continue;

            visited[nx][ny] = true;
            q.push({nx,ny});
            dist[nx][ny] = dist[x][y] + 1;
        }
    }

    for(int i=0; i<sizeX; i++) {
        for(int j=0; j<sizeY; j++) {
            int temp = dist[i][j];
            if(!temp) {
                if(!passable[i][j]) temp = 0;
                else temp = -1;
            }
            cout<<temp<<' ';
        }
        cout<<'\n';
    }
}