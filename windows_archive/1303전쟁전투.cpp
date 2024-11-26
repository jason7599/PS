#include <iostream>
#include <queue>

using namespace std;

int sizeX, sizeY;

char map[100][100];
bool visited[100][100];

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int calcPower(char team) {
    int totalPower = 0;

    for(int x=0; x<sizeX; x++) {
        for(int y=0; y<sizeY; y++) {
            if(visited[x][y]) continue;
            if(map[x][y] != team) continue;

            int power = 0;
            queue<pair<int,int>> q;
            q.push({x,y});
            visited[x][y]=true;

            while(!q.empty()) {
                power++;
                int curX = q.front().first;
                int curY = q.front().second;
                q.pop();
                // visited[curX][curY] = true;

                for(int k=0; k<4; k++) {
                    int nx = curX + dx[k];
                    int ny = curY + dy[k];

                    if(nx < 0 || nx == sizeX || ny <0 || ny == sizeY) continue;
                    if(visited[nx][ny] || map[nx][ny] != team) continue;

                    visited[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
            totalPower+= power*power;
        }
    }

    return totalPower;
}

int main() {
    
    cin>>sizeY>>sizeX;

    for(int i=0; i<sizeX; i++) {
        for(int j=0; j<sizeY; j++) {
            char temp; cin>>temp;
            map[i][j] = temp;
        }
    }

    cout<<calcPower('W')<<' '<<calcPower('B');
}