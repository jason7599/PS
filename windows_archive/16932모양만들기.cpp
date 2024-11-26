#include <iostream>
#include <queue>
#include <map>

using namespace std;

int board[1000][1000];
int boardId[1000][1000];
bool visited[1000][1000];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int sizeX, sizeY;

void calcAreaSize() {
    int id = 0;
    for(int i=0; i<sizeX; i++) {
        for(int j=0; j<sizeY; j++) {
            if(visited[i][j] || !board[i][j]) continue;

            id++;
            visited[i][j] = true;
            queue<pair<int,int>> q;
            queue<pair<int,int>> q2;

            q.push({i,j}); q2.push({i,j});

            int size = 0;
            while(!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop(); size++;

                for(int k=0; k<4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if(nx<0 || nx==sizeX || ny<0 || ny==sizeY
                    || visited[nx][ny] || !board[nx][ny]) continue;

                    visited[nx][ny] = true;
                    q.push({nx,ny}); q2.push({nx,ny});
                }
            }
            // cout<<"size: "<<size<<'\n';
            while(!q2.empty()) {
                int x = q2.front().first;
                int y = q2.front().second;
                board[x][y] = size; q2.pop();
                boardId[x][y] = id;
            }
        }
    }


    // for(int i=0; i<sizeX; i++)
    //     for(int j=0; j<sizeY; j++)
    //         visited[i][j] = false;
}

int main() {
    cin>>sizeX>>sizeY;

    for(int i=0; i<sizeX; i++) {
        for(int j=0; j<sizeY; j++) {
            cin>>board[i][j];
        }
    }

    calcAreaSize();

    // cout<<"board=========\n";
    // for(int i=0; i<sizeX; i++) {
    //     for(int j=0; j<sizeY; j++) {
    //         cout<<board[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }

    int maxSize = 0;
    for(int i=0; i<sizeX; i++) {
        for(int j=0; j<sizeY; j++) {
            if(board[i][j]) continue;

            int size = 1;
            map<int, bool> regis;

            for(int k=0; k<4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];

                if(x<0 || x==sizeX || y<0 || y==sizeY) continue;
                if(!regis[boardId[x][y]]) {
                    size+=board[x][y];
                    regis[boardId[x][y]] = true;
                }
            }
            if(size > maxSize) maxSize = size;
        }
    }

    cout<<maxSize;

}