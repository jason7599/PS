#include <iostream>
#include <queue>

#define INF 987654321
#define pii pair<int, int>

using namespace std;

int n;
int map[100001][100001];
int dist[100001];

void resetDist() {
    for(int i=1; i<=n; i++)
        dist[i] = INF;
}

void mapDistance(int startNode) {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({dist[startNode], startNode});
    dist[startNode] = 0;

    while(!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();
        for(int next=1; next<=n; next++) {
            int nextDist = map[current][next];
            if(nextDist == INF) continue;
            if(nextDist + currentDist < dist[next]) {
                dist[next] = nextDist + currentDist;
                pq.push({dist[next], next});
            }
        }
    }
}

int main() {

    cin>>n;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            map[i][j] = INF;
        }
    }

    for(int i=1; i<=n; i++) {
        map[i][i] = 0;
        dist[i] = INF;
    }


    int a, b, c;
    cin>>a>>b>>c; 

    int m; cin>>m;
    for(int i=0; i<m; i++) {
        int from, to, weight;
        cin>>from>>to>>weight;
        map[from][to] = min(map[from][to], weight);
        map[to][from] = min(map[to][from], weight);
    }

    int farthestPlace = 0;
    int closestDist = INF + 1;

    for(int i=1; i<=n; i++) {
        if(i==a || i==b || i==c) continue;
        mapDistance(i);
        int tempClosestDist = min(dist[a], min(dist[b], dist[c]));
        if(tempClosestDist < closestDist) {
            closestDist = tempClosestDist;
            farthestPlace = i;
        }
        resetDist();
    }

    cout<<farthestPlace;

}