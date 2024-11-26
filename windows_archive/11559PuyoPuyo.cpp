#include <iostream>
#include <queue>

using namespace std;

char board[12][6];
bool visited[12][6];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main() {
    for(int i=0; i<12; i++) {
        for(int j=0; j<6; j++) {
            char temp; cin>>temp;
            board[i][j] = temp;
        }
    }

    int streak = 0;

    while(true) {
        bool pop = false;
        for(int i=0; i<12; i++) {
            for(int j=0; j<6; j++) {
                if(visited[i][j]) continue;
                char cur = board[i][j];
                if(cur == '.') continue;

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

                        if(nx<0 || nx==12 || ny<0 || ny==6) continue;
                        if(visited[nx][ny] || board[nx][ny] != cur) continue;

                        visited[nx][ny] = true;
                        q.push({nx,ny}); popQ.push({nx,ny});
                    }
                }

                if(popQ.size() > 3) {
                    pop = true;
                    // streak++;
                    while(!popQ.empty()) {
                        int x = popQ.front().first;
                        int y = popQ.front().second;
                        popQ.pop();

                        board[x][y] = '.';
                    }
                }
            }
        }

        if(!pop) break;
        streak++;

        for(int row = 11; row>=0; row--) {
            for(int col=0; col<6; col++) {
                visited[row][col] = false;
                char cur = board[row][col];
                if(cur == '.') continue;

                int nextRow = row;

                while(true) {
                    if(nextRow==11 || board[nextRow+1][col] != '.')
                        break;
                    nextRow++;
                }

                board[row][col] = '.';
                board[nextRow][col] = cur;
            }
        }
    }

    cout<<streak;
}