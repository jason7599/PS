#include <iostream>
#include <vector>

using namespace std;

vector<int> edges[1001];
bool visited[1001];

void dfs(int start) {
    visited[start] = true;
    for(int edge : edges[start]) {
        if(!visited[edge]) dfs(edge);
    }
}

int main() {
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++) {
        int from, to;
        cin>>from>>to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }

    int count = 0;
    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            dfs(i);
            count++;
        }
    }

    cout<<count;

}