#include <iostream>
#include <queue>

using namespace std;

int maze[100][100]; 
bool visited[100][100];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main() {
    int sizeX, sizeY;
    cin>>sizeX>>sizeY;

    for(int i=0; i<sizeX; i++) {
        for(int j=0; j<sizeY; j++) {
            char temp; cin>>temp;
            maze[i][j] = temp-'0';
        }
    }

    int count = 0;
    int curX=0, curY=0;
    maze[curX][curY]=1;
    visited[curX][curY] = true;

    queue<pair<int,int>> q;
    q.push({curX,curY});

    while(!q.empty()) {
        curX = q.front().first;
        curY = q.front().second;
        q.pop();
        for(int k=0; k<4; k++) {
            int nx = curX + dx[k];
            int ny = curY + dy[k];
            if(nx<0 || nx==sizeX || ny<0 || ny==sizeY ) continue;
            if(!maze[nx][ny] || visited[nx][ny]) continue;
            maze[nx][ny] = maze[curX][curY] + 1;
            if(nx == sizeX-1 && ny == sizeY-1) {
                cout<<maze[nx][ny];
                return 0;
            }
            visited[nx][ny] = true;
            q.push({nx,ny});
        }
    }
}