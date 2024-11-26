#include <iostream>
#include <queue>

using namespace std;

bool adjMatrix[1001][1001];
bool visited[1001];

int n;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int cur = q.front();
        cout<<cur<<' ';
        q.pop();
        for(int i=1; i<=n; i++) {
            if(adjMatrix[cur][i] && !visited[i]) { 
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void dfs(int cur) {
    cout<<cur<<' ';
    visited[cur] = true;
    for(int i=1; i<=n; i++) {
        if(adjMatrix[cur][i] && !visited[i])
            dfs(i);
    }
}


int main() {
    int m, v;
    cin>>n>>m>>v;

    for(int i=0; i<m; i++) {
        int x, y;
        cin>>x>>y;
        adjMatrix[x][y] = true;
        adjMatrix[y][x] = true;
    }

    dfs(v);
    cout<<'\n';
    for(int i=1; i<=n; i++)
        visited[i] = false;
    bfs(v);
}