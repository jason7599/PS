#include <bits/stdc++.h>
#define PRINT(x) {cout << x << '\n';}
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, s, e) for(int i = s; i <= e; i++)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

vector<int> nexts[32001];
bool vis[32001];

void topo(int n, stack<int>& s) {
    vis[n] = 1;
    for (int nxt : nexts[n]) {
        if (!vis[nxt]) {
            topo(nxt, s);
        }
    }
    s.push(n);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        nexts[a].push_back(b);
    }

    stack<int> s;
    FORR(i, 1, n) {
        if (!vis[i]) {
            topo(i, s);
        }
    }

    for (; !s.empty(); s.pop()) {
        cout << s.top() << ' ';
    }
    cout << '\n';
}