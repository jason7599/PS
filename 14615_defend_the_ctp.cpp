#include <bits/stdc++.h>

using namespace std;

vector<int> roads[100'001][2];
bool visited[100'001][2];

void dfs(int pos, bool dir) {
    visited[pos][dir] = 1;
    for (int next : roads[pos][dir]) {
        if (!visited[next][dir])
            dfs(next, dir);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n_cities, n_roads;
    cin >> n_cities >> n_roads;

    while (n_roads--) {
        int from, to;
        cin >> from >> to;
        roads[from][0].push_back(to);
        roads[to][1].push_back(from);
    }

    dfs(1, 0);
    dfs(n_cities, 1);

    int n_tc;
    cin >> n_tc;

    while (n_tc--) {
        int pos;
        cin >> pos;
        if (visited[pos][0] && visited[pos][1]) 
            cout << "Defend";
        else
            cout << "Destroyed";
        cout << " the CTP\n";
    }
}