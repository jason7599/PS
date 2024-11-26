#include <iostream>
#include <queue>

using namespace std;

int mapSize;
int terrain[100][100];
bool visited[100][100];

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

int safeAreaCount(int height) {

    for(int i=0; i<mapSize; i++) {
        for(int j=0; j<mapSize; j++) {
            visited[i][j] = false;
        }
    }

    int count = 0;
    for(int row = 0; row < mapSize; row++) {
        for(int col = 0; col < mapSize; col++) {
            if(visited[row][col]) continue;
            if(terrain[row][col] <= height) continue;

            queue<pair<int,int>> q;
            q.push({row,col});
            visited[row][col] = true;
            count++;

            while(!q.empty()) {
                int curR = q.front().first;
                int curC = q.front().second;
                q.pop();

                for(int k=0; k<4; k++) {
                    int nx = curR + dx[k];
                    int ny = curC + dy[k];
                    if(nx < 0 || nx == mapSize || ny < 0 || ny == mapSize) continue;
                    if(visited[nx][ny] || terrain[nx][ny] <= height) continue;
                    visited[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
        }
    }

    return count;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>mapSize;

    int minHeight = 100, maxHeight = 1;
    for(int i=0; i<mapSize; i++) {
        for(int j=0; j<mapSize; j++) {
            int input; cin>>input;
            terrain[i][j]=input;
            if(input > maxHeight) maxHeight = input;
            if(input < minHeight) minHeight = input;
        }
    }

    // int maxCount = 0;
    int maxCount = safeAreaCount(0);
    
    for(int i=minHeight; i<maxHeight; i++) {
        int temp = safeAreaCount(i);
        if(temp > maxCount) maxCount = temp;
    }
    cout<<maxCount;
}