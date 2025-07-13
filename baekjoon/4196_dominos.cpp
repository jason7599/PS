#include <bits/stdc++.h>
#define PRINT(x) {cout << x << '\n';}
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, s, e) for(int i = s; i <= e; i++)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

bool vis[100'001];
vector<int> edges[100'001];

void topo(int n, stack<int>& stk) {
    vis[n] = 1;
    for (int nx : edges[n]) {
        if (!vis[nx]) {
            topo(nx, stk);
        }
    }
    stk.push(n);
}

int dfs(int n) {
    vis[n] = 0;
    int res = 1;
    for (int nx : edges[n]) {
        if (vis[nx]) {
            res += dfs(nx);
        }
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_tc;
    cin >> n_tc;
    while (n_tc--) {
        int n_doms, n_rels;
        cin >> n_doms >> n_rels;
        FORR(i, 1, n_doms) {
            edges[i].clear();
        }

        while (n_rels--) {
            int a, b;
            cin >> a >> b;
            edges[a].push_back(b);
        }
        
        stack<int> stk;
        FORR(i, 1, n_doms) {
            if (!vis[i]) {
                topo(i, stk);
            }
        }
        
        int ans = 0;
        for (int collapsed = 0; collapsed < n_doms; stk.pop()) {
            if (vis[stk.top()]) {
                collapsed += dfs(stk.top());
                ans++;
            }
        }
        PRINT(ans)
    }
}