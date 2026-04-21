#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0, _n = n; i < _n; i++)
#define RANGE(i, s, e) for (int i = s, _e = e; i <= _e; i++)
#define REP(n) for (int _ = 0, _n = n; _ < _n; _++)
#define DBG(x) cerr << #x << " = " << x << '\n'
#define LF cout << '\n'
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
template<typename T = int> T input() { T t; cin >> t; return t; }
template<typename T> T& input(T& t) { cin >> t; return t; }
template<typename... Args> void input(Args&... args) { ((cin >> args), ...); }
template<typename... Args> tuple<Args...> inputs() { tuple<Args...> t; apply([](auto&... args){input(args...);}, t); return t; }
template<typename T, int C> array<T, C> inputs() { array<T, C> arr; for (T& t : arr) cin >> t; return arr; }
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF; }
template<typename T> T& upmax(T& v, const T& other) { return v = max(v, other); }
template<typename T> T& upmin(T& v, const T& other) { return v = min(v, other); }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // drul

vector<int> edges[100'001];
int vis[100'001];

void dfs(int n) {
    static int v;
    vis[n] = ++v;
    sort(edges[n].begin(), edges[n].end());
    for (int nxt : edges[n]) {
        if (!vis[nxt]) {
            dfs(nxt);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    auto [n_nodes, n_edges, start] = inputs<int, 3>();

    REP(n_edges) {
        auto [a, b] = inputs<int, 2>();
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(start);

    RANGE(i, 1, n_nodes) {
        print(vis[i]);
    }
}