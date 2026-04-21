#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0, __n = n; i < __n; i++)
#define RANGE(i, s, e) for(int i = s, __e = e; i <= __e; i++)
#define REP(n) FOR(__, n)
#define LF {cout << '\n';}
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
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF }
template<typename T> T upmax(T& v, const T& other) { v = max(v, other); return v; }
template<typename T> T upmin(T& v, const T& other) { v = min(v, other); return v; }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

const int MX_NODE = 100'001;

int n_nodes;
vector<pii> edges[MX_NODE]; // <to, color>
vector<pii> prevs[MX_NODE];

int vis[MX_NODE];
bool opt_path[MX_NODE];

void bfs() {
    queue<int> q({1});
    vis[1] = 1;

    for (int q_size, time = 2; (q_size = q.size()); time++) {
        while (q_size--) {
            int cur = q.front();
            q.pop();

            for (const auto& [nxt, col] : edges[cur]) {
                if (!vis[nxt] || vis[nxt] == time) {
                    vis[nxt] = time;
                    q.push(nxt);
                    prevs[nxt].push_back({cur, col});
                }
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(n_nodes);
    REP(input()) { // n_edges
        auto [a, b, c] = inputs<int, int, int>();
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    
    RANGE(i, 1, n_nodes) {
        sort(edges[i].begin(), edges[i].end(), [](pii lhs, pii rhs) {
            return lhs.se < rhs.se;
        });
    }

    bfs();
}