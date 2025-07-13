#include <bits/stdc++.h>
#define PRINT(x) {cout << x << '\n';}
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, s, e) for(int i = s; i <= e; i++)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int n_nodes;
bool vis[10'001];
vector<int> edges[10'001];

void toposort(int n, stack<int>& stk) {
    vis[n] = 1;
    for (int nx : edges[n]) {
        if (!vis[nx]) {
            toposort(nx, stk);
        }
    }
    stk.push(n);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_edges;
    cin >> n_nodes >> n_edges;
    while (n_edges--) {
        int a, b;
        cin >> a >> b;
        edges[b].push_back(a);
    }

    stack<int> stk;
    toposort(2, stk);    
}