#include <iostream>
#include <queue>

#define INF 987654321
#define pip pair<int, pair<int, int>>

using namespace std;

int mapSize;
bool black[50][50];
int dist[50][50];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main() {
    cin>>mapSize;

    for(int i=0; i<mapSize; i++) {
        for(int j=0; j<mapSize; j++) {
            dist[i][j] = INF;
            char temp; cin>>temp;
            black[i][j] = temp == '0';
        }
    }

    priority_queue<pip, vector<pip>, greater<pip>> pq;
    dist[0][0] = 0; pq.push({0, {0,0}});

    while(!pq.empty()) {
        int curX = pq.top().second.first;
        int curY = pq.top().second.second;
        int curDist = pq.top().first;
        pq.pop();

        for(int k=0; k<4; k++) {
            int nx = curX + dx[k];
            int ny = curY + dy[k];
            if(nx<0 || nx==mapSize || ny<0 || ny==mapSize) continue;
            int nDist = black[nx][ny] ? 1 : 0;
            if(curDist + nDist < dist[nx][ny]) {
                dist[nx][ny] = curDist + nDist;
                pq.push({dist[nx][ny], {nx,ny}});
            }
        }
    }

    cout<<dist[mapSize-1][mapSize-1];
}