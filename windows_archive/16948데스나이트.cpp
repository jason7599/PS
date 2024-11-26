#include <iostream>
#include <queue>

using namespace std;

int boardSize;

int dist[200][200];
bool visited[200][200];

int dx[] = {-2, -2, 0, 0, 2, 2};
int dy[] = {-1, 1, -2, 2, -1, 1};

void calcDistance(int startX, int startY) {
    dist[startX][startY] = 0;
    visited[startX][startY] = true;
    queue<pair<int,int>> q;
    q.push({startX, startY});

    while(!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second; 
        q.pop();

        for(int k = 0; k< 6; k++) {
            int nx = curX + dx[k];
            int ny = curY + dy[k];
            if(nx < 0 || nx >= boardSize || ny < 0 || ny >= boardSize) continue;
            if(visited[nx][ny]) continue;
            visited[nx][ny]=true;
            dist[nx][ny] = dist[curX][curY] + 1;
            q.push({nx, ny});
        }
    }
}

int main() {
    cin>>boardSize;

    int startX, startY, endX, endY;
    cin>>startX>>startY>>endX>>endY;

    // for(int k=0; k<6; k++) {
    //     int nx = startX + dx[k];
    //     int ny = startY + dy[k];
    //     if(nx < 0 || nx >= boardSize
    //     || ny < 0 || ny >= boardSize) continue;
    //     dist[nx][ny]=1;
    // }

    calcDistance(startX, startY);
    // for(int i=0; i<boardSize; i++) {
    //     for(int j=0; j<boardSize; j++) {
    //         cout<<dist[i][j];
    //         cout<<" ";
    //     }
    //     cout<<endl;
    // }

    int ans = dist[endX][endY];

    if(ans) cout<< ans;
    else cout<< -1;
}