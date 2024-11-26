#include <iostream>
#include <queue>

using namespace std;

int sizeX, sizeY;
int tomato[1000][1000];
// bool visited[1000][1000];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main() {
    cin>>sizeY>>sizeX;

    int tomatoesLeft = 0;
    queue<pair<int,int>> q;
    for(int i=0; i<sizeX; i++) {
        for(int j=0; j<sizeY; j++) {
            int temp; cin>>temp;
            tomato[i][j] = temp;
            // visited[i][j] = true;
            if(temp==1) q.push({i,j});
            else if(!temp) tomatoesLeft++;
        }
    }

    int days = 0;
    while(true) {
        bool deadlock = true;
        int qSize = q.size();
        for(int i=0; i<qSize; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k=0; k<4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx<0 || nx==sizeX || ny<0 || ny==sizeY
                || tomato[nx][ny]) continue; //visited 체크 안해줘도 될거같은데

                deadlock = false;
                tomatoesLeft--;
                tomato[nx][ny] = 1;
                // visited[nx][ny] = true;
                q.push({nx,ny});
            }
        }
        if(deadlock) break;

        days++;
    }

    if(tomatoesLeft) cout<<-1;
    else cout<<days;
}