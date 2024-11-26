#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100001;
vector<int> adjList[MAX];
int parent[MAX];
bool visited[MAX];

int main() {

    int n; cin>>n;

    for(int i=1; i<n; i++) {
        int x, y;
        cin>>x>>y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int child : adjList[cur]) {
            if(!visited[child]) {
                parent[child] = cur;
                visited[child] = true;
                q.push(child);
            }
        }
    }

    for(int i=2; i<=n; i++)
        cout<<parent[i]<<'\n';

}