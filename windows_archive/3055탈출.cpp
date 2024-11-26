#include <iostream>
#include <queue>

using namespace std;

int sizeX, sizeY;

char map[50][50];
bool visited[50][50];



int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main() {
    cin>>sizeX>>sizeY;

    queue<pair<int,int>> traverseQ;
    queue<pair<int,int>> waterQ;
    for(int i=0; i<sizeX; i++) {
        for(int j=0; j<sizeY; j++) {
            char temp; cin>>temp;
            if(temp == 'S') {
                traverseQ.push({i,j});
                visited[i][j] = true;
            }
            else if(temp == '*') {
                waterQ.push({i,j});
            }
        }
    }

    int time = 0;
    while(true) {
        time++;
        int waterQSize = waterQ.size();
        for(int i=0; i<waterQSize; i++) {
            int x = waterQ.front().first;
            int y = waterQ.front().second;
            waterQ.pop();
            for(int k=0; k<4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx<0 || nx==sizeX
                || ny<0 || ny==sizeY
                || map[nx][ny] == 'D'
                || map[nx][ny] == 'X') continue;
                if(map[nx][ny] == 'S') {
                    cout<<"KAKTUS";
                    return 0;
                }
                waterQ.push({nx,ny});
                map[nx][ny] = '*';
            }
        }
        int traverseQSize = traverseQ.size();
        // while(!traverseQ.empty()) {
        for(int i=0; i<traverseQSize; i++) {
            int x = traverseQ.front().first;
            int y = traverseQ.front().second;
            traverseQ.pop();
            for(int k=0; k<4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx<0 || nx==sizeX
                || ny<0 || ny==sizeY
                || map[nx][ny] == '*'
                || map[nx][ny] == 'X'
                || visited[nx][ny]) continue;
                if(map[nx][ny] == 'D') break;
                traverseQ.push({nx,ny});
                visited[nx][ny] = true;
            }
        }
        time++;
    }

    cout<<time;
}