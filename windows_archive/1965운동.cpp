#include <iostream>
#include <algorithm>

using namespace std;

#define INF 987654321

int nodeCount, dist[401][401];

void floyd() {
    for (int k = 1; k <= nodeCount; k++) {
        for (int i = 1; i <= nodeCount; i++) {
            if (i == k) continue;
            for (int j = 1; j <= nodeCount; j++) {
                if (j == k) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {

    int edgeCount;
    cin >> nodeCount >> edgeCount;

    for (int i = 1; i <= nodeCount; i++)
        for(int j = 1; j <= nodeCount; j++)
            dist[i][j] = INF;

    while (edgeCount--) {
        int from, to, cost;
        cin >> from >> to >> cost;
        dist[from][to] = cost;
    }

    floyd();

    int ans = INF;
    for (int i = 1; i <= nodeCount; i++)
        ans = min(ans, dist[i][i]);

    if (ans == INF) cout << -1;
    else cout << ans;

}