#include <iostream>
#include <queue>
#define INF 987654321
#define MAX 100001

using namespace std;

// int nodes[MAX][MAX];
int dist[MAX];

int main() {

    // for(int i=1; i<MAX; i++) {
    //     for(int j=1; j<MAX; j++) {
    //         nodes[i][j] = INF;
    //     }
    // }

    for(int i=0; i<MAX; i++) {
        // nodes[i][i] = 0;
        dist[i] = INF;
    }

    int start, end;
    cin>>start>>end;

    dist[start] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push({dist[start], start}); //거리, 노드

    while(!pq.empty()) {
        int curNode = pq.top().second;
        int distSoFar = pq.top().first;
        pq.pop();

        for(int i=0; i<3; i++) {
            int next;
            int distance;
            if(i==0) {
                next = curNode-1;
                distance = 1;
            }
            else if(i==1) {
                next = curNode+1;
                distance = 1;
            }
            else {
                next = curNode*2;
                distance = 0;
            }
            if(next <0 || next > MAX) continue;
            if(distSoFar + distance < dist[next]) {
                dist[next] = distSoFar + distance;
                pq.push({dist[next], next});
            }
        }
    }

    cout<<dist[end];
}