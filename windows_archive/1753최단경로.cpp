#include <iostream>
#include <queue>
#define INF 987654321

using namespace std;

// int nodes[20001][20001];
vector<pair<int,int> > vertex[20001];
int dist[20001];

int main() {
    int nodeCount, edgeCount;
    cin>>nodeCount>>edgeCount;

    // for(int i=1; i<=nodeCount; i++) {
    //     for(int j=1; j<=nodeCount; j++) {
    //         // nodes[i][j] = INF;
    //         vertex[]
    //     }
    // }

    for(int i=1; i<=nodeCount; i++) {
        // nodes[i][i] = 0;
        dist[i] = INF;
    }

    int start; cin>>start;
    dist[start] = 0;

    for(int i=0; i<edgeCount; i++) {
        int from, to, weight;
        cin>>from>>to>>weight;

        // if(nodes[from][to] > weight) {
        //     nodes[from][to] = weight;
        //     // cout<<"fuck\n";
        // }

        vertex[from].push_back({to, weight});
    }

    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push({dist[start], start}); // 거리, 노드

    while(!pq.empty()) {
        int currentNode = pq.top().second;
        int currentDistance = pq.top().first;
        pq.pop();

        // for(int next = 1; next <= nodeCount; next++) {
        for(auto v : vertex[currentNode]) {
            // int distance = nodes[currentNode][next];
            int next = v.first;
            int distance = v.second;
            if(distance == INF) continue;

            if(distance + currentDistance < dist[next]) {
                dist[next] = distance + currentDistance;
                pq.push({dist[next], next});
            }  
        }
    }

    for(int i=1; i<=nodeCount; i++) {
        if(dist[i] == INF) cout<<"INF\n";
        else cout<<dist[i]<<'\n';
    }

}