#include <iostream>
#include <queue>

#define INF 987654321
#define pip pair<int, pair<int,int>>

using namespace std;

int sizeX, sizeY;
bool wall[100][100];
int dist[100][100];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main() {
    cin>>sizeX>>sizeY; //순서 조심

    for(int i=0; i<sizeY; i++) { //
        for(int j=0; j<sizeX; j++) {
            char temp; cin>>temp;
            wall[i][j] = temp == '1';
            dist[i][j] = INF;
        }
    }

    priority_queue<pip, vector<pip>, greater<pip>> pq; //거리, x,y
    dist[0][0] = 0;
    pq.push({dist[0][0], {0,0}});

    while(!pq.empty()) {
        int curX = pq.top().second.second;
        int curY = pq.top().second.first;
        int curDist = pq.top().first;
        pq.pop();
        for(int k=0; k<4; k++) {
            int nx = curX + dx[k];
            int ny = curY + dy[k];
            if(nx<0 || nx==sizeX || ny<0 || ny==sizeY) continue;
            int nextDist = wall[ny][nx] ? 1 : 0;

            if(curDist + nextDist < dist[ny][nx]) {
                dist[ny][nx] = curDist + nextDist;
                pq.push({dist[ny][nx] , {ny, nx}});
            }
        }
    }
    
    cout<<dist[sizeY-1][sizeX-1];

}