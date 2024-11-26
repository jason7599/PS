#include <iostream>
#include <queue>

#define INF 987654321
#define pii pair<int, int>

using namespace std;

int n;
int map[1001][1001];
int dist[1001];
int totalDist[1001];

void resetDist() {
    for(int i=1; i<=n; i++)
        dist[i] = INF;
}

void dijkstra(int start) {
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({dist[start], start});

    while(!pq.empty()) {
        int cur = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();

        for(int i=1; i<=n; i++) {
            int next = i;
            int nextDist = map[cur][next];
            if(nextDist == INF) continue;

            if(nextDist + curDist < dist[next]) {
                dist[next] = nextDist + curDist;
                pq.push({dist[next], next});
            }
        }
    }
}

int main() {

    int m, x;
    cin>>n>>m>>x;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            map[i][j] = INF;
        }
    }
    for(int i=1; i<=n; i++) {
        map[i][i] = 0;
        dist[i] = INF;
    }

    for(int i=0; i<m; i++) {
        int from, to, weight;
        cin>>from>>to>>weight;
        map[from][to] = weight;
    }

    dijkstra(x);
    for(int i=1; i<=n; i++) {
        totalDist[i]+=dist[i];
    }
    resetDist();

    int maxDist = 0;
    for(int i=1; i<=n; i++) {
        dijkstra(i);
        totalDist[i]+=dist[x];
        if(maxDist < totalDist[i])
            maxDist = totalDist[i];
        resetDist();
    }

    cout<<maxDist;
}