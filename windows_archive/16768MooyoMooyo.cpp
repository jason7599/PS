#include <iostream>
#include <queue>

using namespace std;

int grid[100][10];
bool visited[100][10];

int gridSize;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main() {

    int k;
    cin>>gridSize>>k;

    for(int i=0; i<gridSize; i++) {
        for(int j=0; j<10; j++) {
            char temp; cin>>temp;
            grid[i][j] = temp-'0';
        }
    }

    while(true) {
        bool pop = false;
        for(int i=0; i<gridSize; i++) {
            for(int j=0; j<10; j++) {
                if(visited[i][j]) continue;
                int cur = grid[i][j];
                if(!cur) continue;

                queue<pair<int,int>> q;
                queue<pair<int,int>> popQ;
                q.push({i,j}); popQ.push({i,j});
                visited[i][j] = true;

                while(!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for(int k=0; k<4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if(nx<0 || nx==gridSize || ny<0 || ny==10) continue;
                        if(visited[nx][ny] || grid[nx][ny] != cur) continue;

                        visited[nx][ny] = true;
                        q.push({nx,ny}); popQ.push({nx,ny});
                    }
                }

                if(popQ.size() >= k ) {
                    pop = true;
                    // streak++;
                    while(!popQ.empty()) {
                        int x = popQ.front().first;
                        int y = popQ.front().second;
                        popQ.pop();

                        grid[x][y] = 0;
                    }
                }
            }
        }

        if(!pop) break;

        for(int row = gridSize-1; row>=0; row--) {
            for(int col=0; col<10; col++) {
                visited[row][col] = false;
                int cur = grid[row][col];
                if(!cur) continue;

                int nextRow = row;

                while(true) {
                    if(nextRow==gridSize-1 || grid[nextRow+1][col])
                        break;
                    nextRow++;
                }

                grid[row][col] = 0;
                grid[nextRow][col] = cur;
            }
        }

        // printGrid();
    }

    for(int i=0; i<gridSize; i++) {
        for(int j=0; j<10; j++) {
            cout<<grid[i][j];
        }
        cout<<'\n';
    }
}