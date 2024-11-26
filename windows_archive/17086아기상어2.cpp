#include <iostream>
#include <queue>

using namespace std;

int sizeX, sizeY;

bool shark[50][50];
bool visited[50][50];

int dx[] = {1,-1,0,0,1,1,-1,-1};
int dy[] = {0,0,1,-1,1,-1,-1,1};

int main() {
    cin>>sizeX>>sizeY;

    for(int i=0; i<sizeX; i++) {
        for(int j=0; j<sizeY; j++) {
            int temp; cin>>temp;
            shark[i][j] = temp;
        }
    }

    int maxDist = 0;

    for(int i=0; i<sizeX; i++) {
        for(int j=0; j<sizeY; j++) {
            if(shark[i][j]) continue;
            bool stop = false;
            queue<pair<int,int>> q;
            q.push({i,j});
            visited[i][j] = true;
            int dist = 0;
            while(!q.empty()) {
                int t = q.size();
                for(int k=0; k<t; k++) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int d=0; d<8; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if(nx<0 || nx==sizeX || ny<0 || ny==sizeY
                        || visited[nx][ny]) continue;
                        if(shark[nx][ny]) {
                            stop = true;
                            break;
                        }
                        // cout<<nx<<' '<<ny<<'\n';
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                    if(stop) break;
                }
                dist++;
                if(stop) break;
            }
            if(dist > maxDist) maxDist = dist;
            for(int n=0; n<sizeX; n++){
                for(int m=0; m<sizeY; m++) {
                    visited[n][m] = false;
                }
            }
        }
    }

    cout<<maxDist;
}