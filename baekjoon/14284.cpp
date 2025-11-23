#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0, _n = n; i < _n; i++)
#define RANGE(i, s, e) for (int i = s, _e = e; i <= _e; i++)
#define REP(n) for (int _ = 0, _n = n; _ < _n; _++)
#define STR(x) #x
#define DBG(x) cerr << #x << " = " << x << '\n'
#define EE(p) (ll)(1e##p)
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

vector<pii> edges[5001];
int dmap[5001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    auto [n_nodes, n_edges] = inputs<int, 2>();
    fill(&dmap[1], &dmap[n_nodes + 1], INT_MAX);

    REP(n_edges) {
        auto [a, b, cost] = inputs<int, 3>();
        edges[a].push_back({b, cost});
        edges[b].push_back({a, cost});
    }

    auto [src, dst] = inputs<int, 2>();
    dmap[src] = 0;

    priority_queue<pii> pq;
    pq.push({0, src});

    while (pq.size()) {
        int dist = -pq.top().fi;
        int cur = pq.top().se;
        pq.pop();

        if (dmap[cur] < dist) {
            continue;
        }

        if (cur == dst) {
            break;
        }

        for (const auto& [nxt, cost] : edges[cur]) {
            int nxt_dist = dist + cost;
            if (dmap[nxt] > nxt_dist) {
                dmap[nxt] = nxt_dist;
                pq.push({-nxt_dist, nxt});
            }
        }
    }

    print(dmap[dst]);
}