#include <iostream>
#include <queue>

#define pip pair<int,pair<int,int>>
#define INF 2147483647

using namespace std;

int map[125][125];
int dist[125][125];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main() {

    int num = 0;
    while(true) {
        int n; cin>>n;
        if(!n) break;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin>>map[i][j];
                dist[i][j] = INF;
            }
        }
        dist[0][0] = map[0][0];
        priority_queue<pip, vector<pip>, greater<pip>> pq;
        pq.push({dist[0][0], {0,0}});

        while(!pq.empty()) {
            int curX = pq.top().second.first;
            int curY = pq.top().second.second;
            int curD = pq.top().first;
            pq.pop();

            for(int k=0; k<4; k++) {
                int nx = curX + dx[k];
                int ny = curY + dy[k];
                if(nx<0 || nx==n || ny<0 || ny==n) continue;
                int nd = curD + map[nx][ny];
                if(nd < dist[nx][ny]) {
                    dist[nx][ny] = nd;
                    pq.push({nd, {nx, ny}});
                }
            }
        }

        cout<<"Problem "<<++num<<": "<<dist[n-1][n-1]<<'\n';
    }
}