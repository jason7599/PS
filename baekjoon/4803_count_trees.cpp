#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0, _n = n; i < _n; i++)
#define RANGE(i, s, e) for (int i = s, _e = e; i <= _e; i++)
#define REP(n) for (int _ = 0, _n = n; _ < _n; _++)
#define STR(x) #x
#define DEBUG(x) cerr << #x << " = " << x << '\n'
#define LF cout << '\n'
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
template<typename T = int> T input() { T t; cin >> t; return t; }
template<typename T> T input(T& t) { cin >> t; return t; }
template<typename... Args> void input(Args&... args) { ((cin >> args), ...); }
template<typename... Args> tuple<Args...> inputs() { tuple<Args...> t; apply([](auto&... args){input(args...);}, t); return t; }
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF; }
template<typename T> T upmax(T& v, const T& other) { v = max(v, other); return v; }
template<typename T> T upmin(T& v, const T& other) { v = min(v, other); return v; }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

vector<int> edges[501];
bool vis[501];

bool dfs(int n, int p) {
    vis[n] = 1;
    for (int nx : edges[n]) {
        if (nx != p) {
            if (vis[nx] || !dfs(nx, n)) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    for (int tc = 1;; tc++) {
        auto [n_nodes, n_edges] = inputs<int, int>();
        if (!n_nodes) {
            break;
        }

        RANGE(i, 1, n_nodes) {
            edges[i].clear();
            vis[i] = 0;
        }

        REP(n_edges) {
            auto [a, b] = inputs<int, int>();
            edges[a].push_back(b);
            edges[b].push_back(a);
        }

        int cnt = 0;
        RANGE(i, 1, n_nodes) {
            if (!vis[i] && dfs(i, 0)) {
                cnt++;
            }
        }

        cout << "Case " << tc << ": ";
        if (cnt == 0) {
            print("No trees.");
        } else if (cnt == 1) {
            print("There is one tree.");
        } else {
            print("A forest of", cnt, "trees.");
        }
    }
}