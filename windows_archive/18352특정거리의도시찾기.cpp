#include <iostream>
#include <queue>

using namespace std;

vector<int> map[300001];
int dist[300001];

int main() {

    int n, m ,k, x;
    cin>>n>>m>>k>>x;

    for(int i=0; i<m; i++) {
        int from, to;
        cin>>from>>to;
        map[from].push_back(to);
    }

    for(int i=1; i<=n; i++) {
        dist[i] = 2147483647;
    }

    queue<int> q; q.push(x);
    dist[x] = 0;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int to : map[cur]) {
            if(dist[to] > dist[cur] + 1) {
                dist[to] = dist[cur]+1;
                q.push(to);
            }
        }
    }

    bool check = false;
    for(int i=1; i<=n; i++) {
        if(dist[i] == k) {
            cout<<i<<'\n';
            check = true;
        }
    }

    if(!check) cout<<-1;
}