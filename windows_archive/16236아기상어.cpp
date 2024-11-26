#include <iostream>
#include <queue>

using namespace std;

int mapSize;
int map[20][20];
int dist[20][20];
bool visited[20][20];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int sharkX, sharkY;
int sharkSize = 2;
int tilNextGrowth = 2;

void debug();

int main() {
    cin>>mapSize;

    for(int i=0; i<mapSize; i++) {
        for(int j=0; j<mapSize; j++) {
            int temp; cin>>temp;
            if(temp == 9) {
                sharkX = i;
                sharkY = j;
            }
            map[i][j] = temp;
        }
    }

    int time = 0;
    while(true) {

        // cout<<"모든 거리 계산\n";

        queue<pair<int,int>> q;
        q.push({sharkX,sharkY});
        visited[sharkX][sharkY]=true;
        dist[sharkX][sharkY] = 0;

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k=0; k<4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx<0 || nx==mapSize || ny<0 || ny==mapSize) continue;
                if(visited[nx][ny] || sharkSize < map[nx][ny]) continue;

                q.push({nx,ny});
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
            }
        }

        // debug();

        // cout<<"최단 거리 추출\n";
        int minLength = 2147483647;
        bool deadlock = true;
        for(int i=0; i<mapSize; i++) {
            for(int j=0; j<mapSize; j++) {
                if(dist[i][j] && dist[i][j] < minLength && sharkSize > map[i][j] && map[i][j] != 9 && map[i][j]) {
                    minLength = dist[i][j];
                    deadlock = false;
                }
            }
        }
        if(deadlock) break; //엄마 도와줘요

        // cout<<"먹을 상어 선택\n";
        for(int i=0; i<mapSize; i++) {
            bool flag = false;
            for(int j=0; j<mapSize; j++) {
                if(dist[i][j] == minLength && sharkSize > map[i][j] && map[i][j] != 9 && map[i][j]) {
                    map[sharkX][sharkY] = 0;
                    sharkX = i; sharkY = j;
                    map[sharkX][sharkY] = 9;

                    time += minLength;

                    if(!(--tilNextGrowth)) tilNextGrowth = ++sharkSize;  //레벨업

                    // cout<<"["<<sharkX<<"]["<<sharkY<<"] 먹음\n";
                    // cout<<"크기 = "<<sharkSize<<'\n';

                    flag = true; break;
                }
            }
            if(flag) break;
        }

        for(int i=0; i<mapSize; i++) {
            for(int j=0; j<mapSize; j++) {
                visited[i][j] = false;
                // dist[i][j] = 2147483647;
            }
        }
    }

    cout<<time;
}

void debug() {
    cout<<"크기 = "<<sharkSize<<'\n';

    cout<<"map==========\n";
    cout<<"  ";
    for(int i=0; i<mapSize; i++)
        cout<<"["<<i<<"]";
    cout<<'\n';
    for(int i=0; i<mapSize; i++) {
        cout<<"["<<i<<"] ";
        for(int j=0; j<mapSize; j++) {
            cout<<map[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<"=============\n";

    cout<<"dist==========\n";
    cout<<"  ";
    for(int i=0; i<mapSize; i++)
        cout<<"["<<i<<"]";
    cout<<'\n';
    for(int i=0; i<mapSize; i++) {
        cout<<"["<<i<<"] ";
        for(int j=0; j<mapSize; j++) {
            cout<<dist[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<"=============\n";

}