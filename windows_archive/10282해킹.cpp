#include <iostream>
#include <queue>

#define INF 2147483647
#define pii pair<int,int>

using namespace std;

// int adjMatrix[10001][10001];
int dist[10001];

int main() {
    int n; cin>>n;
    for(int i=0; i<n; i++) {
        int computerCount, edgeCount, start;
        cin>>computerCount>>edgeCount>>start;

        for(int j=1; j<=computerCount; j++) {
            // hacked[j] = j==start;
            dist[j] = j==start? 0 : INF;
            // for(int k=1; k<=computerCount; k++) {
            //     // adjMatrix[j][k] = j==k ? 0 : INF;
            // }
        }

        vector<pair<int,int>> adjList[10001];
        for(int j=0; j<edgeCount; j++) {
            int from, to, weight;
            cin>>to>>from>>weight;
            // adjMatrix[from][to] = weight;
            adjList[from].push_back({to,weight});
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({dist[start], start});

        while(!pq.empty()) {
            int cur = pq.top().second;
            int curD = pq.top().first;
            // cout<<"cur="<<cur<<'\n';
            // cout<<"curD="<<curD<<'\n';
            pq.pop();
            // for(int j=1; j<=computerCount; j++) {
            //     int distance = adjMatrix[cur][j];
            //     // cout<<"adjMatrix["<<cur<<"]["<<j<<"]="<<distance<<'\n';
            //     if(distance == INF) continue;
            //     if(curD + distance < dist[j]) {
            //         dist[j] = curD + distance;
            //         pq.push({dist[j], j});
            //         // cout<<"pushing "<<j<<'\n';
            //     }
            // }
            for(auto v : adjList[cur]) {
                int next = v.first;
                int distance = v.second;
                if(curD + distance < dist[next]) {
                    dist[next] = curD + distance;
                    pq.push({dist[next], next});
                }
            }
        }

        int hackCount=0, lastComputer=0;
        for(int j=1; j<=computerCount; j++) {
            if(dist[j] != INF) {
                hackCount++;
                if(dist[j] > lastComputer)
                    lastComputer = dist[j];
            }
        }

        cout<<hackCount<<' '<<lastComputer<<'\n';
    }
}