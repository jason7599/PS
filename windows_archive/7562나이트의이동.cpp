#include <iostream>
#include <queue>

using namespace std;

int dist[300][300];
bool visited[300][300];

int dx[] = {1,2,2,1,-1,-2,-2,-1};
int dy[] = {2,1,-1,-2,-2,-1,1,2};

int main() {
    
    int n; cin>>n;

    //아 함수로 만들걸
    for(int t=0; t<n; t++) {
        int boardSize; cin>>boardSize;

        if(t) {
            for(int i=0; i<boardSize; i++) {
                for(int j=0; j<boardSize; j++) {
                    dist[i][j]=0;
                    visited[i][j]=false;
                }
            }
        }

        int startX, startY;
        cin>>startX>>startY;

        int endX, endY;
        cin>>endX>>endY;

        if(startX == endX && startY == endY) {
            cout<<0<<'\n'; continue;
        }

        queue<pair<int,int>> q; 
        q.push({startX, startY});
        visited[startX][startY] = true;

        bool flag = false;
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int k=0; k<8; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx<0 || nx>=boardSize
                || ny<0 || ny>=boardSize
                || visited[nx][ny]) continue;
                
                dist[nx][ny] = dist[x][y] + 1;
                if(nx==endX && ny==endY) {flag = true; break;}
                q.push({nx,ny}); visited[nx][ny] = true;

            }
            if(flag) break;
        }
        cout<< dist[endX][endY]<<'\n';
    }

}