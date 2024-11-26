#include <iostream>
#include <queue>

using namespace std;

int sizeX, sizeY;
bool land[50][50];
bool visited[50][50];
int dist[50][50];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int findMaxLength(int startX, int startY);

int main() {

    cin>>sizeX>>sizeY;

    for(int i=0; i<sizeX; i++) {
        for(int j=0; j<sizeY; j++) {
            char temp; cin>>temp;
            land[i][j] = (temp=='L');
        }
    }

    int maxLength = 0;
    for(int i=0; i<sizeX; i++) {
        for(int j=0; j<sizeY; j++) {
            if(!land[i][j]) continue;
            int temp = findMaxLength(i,j);
            if(temp > maxLength) maxLength = temp;
        }
    }

    cout<<maxLength;

}

int findMaxLength(int startX, int startY) {

    visited[startX][startY] = true;
    dist[startX][startY] = 0;
    queue<pair<int,int>> q;
    q.push({startX, startY});

    int length = 0;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int k=0; k<4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx<0 || nx==sizeX || ny<0 || ny==sizeY
            || visited[nx][ny] || !land[nx][ny]) continue;

            q.push({nx,ny}); visited[nx][ny] = true;
            dist[nx][ny] = dist[x][y] + 1;
            if(dist[nx][ny] > length) length = dist[nx][ny];
        }
    }

    for(int i=0; i<sizeX; i++) {
        for(int j=0; j<sizeY; j++) {
            visited[i][j] = false;
        }
    }

    return length;
}
