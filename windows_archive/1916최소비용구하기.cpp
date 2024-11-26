#include <iostream>
#include <queue>
#define INF 987654321

using namespace std;

int n;
int nodes[1001][1001];
int dist[1001];

int main() {
    cin>>n;
    int m; cin>>m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            nodes[i][j] = INF;
        }
    }

    for(int i=1; i<=n; i++) {
        nodes[i][i] = 0;
        dist[i] = INF;
    }

    for(int i=1; i<=m; i++) {
        int from, to, cost;
        cin>>from>>to>>cost;
        if(nodes[from][to] > cost)
            nodes[from][to] = cost;
    }

    int start, end;
    cin>>start>>end;
    dist[start] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push({dist[start], start}); //{거리, 노드}

    while(!pq.empty()) {
        int cur = pq.top().second;
        int cost = pq.top().first; //현재까지 거리
        pq.pop();
        
        for(int i=1; i<=n; i++) {
            int distance = nodes[cur][i];
            if(distance == INF) continue; //연결이 안 되어 있는 경우
            
            if(distance + cost < dist[i]) {
                dist[i] = distance + cost;
                pq.push({dist[i], i});
            }
        }
    }

    cout<<dist[end];

}