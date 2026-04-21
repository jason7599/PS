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
template<typename T> bool upmax(T& v, const T& other) { if (v >= other) return 0; v = other; return 1; }
template<typename T> bool upmin(T& v, const T& other) { if (v <= other) return 0; v = other; return 1; }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

const int MX = 1e5;

int n_nodes;
bool los[MX];
vector<pii> edges[MX];
ll dmap[MX];

ll f() {
    priority_queue<pair<ll, int>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        ll time = -pq.top().fi;
        int node = pq.top().se;
        pq.pop();

        if (dmap[node] < time) {
            continue;
        }

        for (const auto& [nxt, t] : edges[node]) {
            ll nxt_t = time + t;
            if (nxt_t < dmap[nxt]) {
                dmap[nxt] = nxt_t;
                pq.push({-nxt_t, nxt});
            }
        }
    }

    return dmap[n_nodes - 1] == INT64_MAX ? -1 : dmap[n_nodes - 1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n_edges;
    input(n_nodes, n_edges);
    FOR(i, n_nodes) {
        input(los[i]);
        dmap[i] = INT64_MAX;
    }
    los[n_nodes - 1] = 0;
    dmap[0] = 0;

    REP(n_edges) {
        auto [a, b, t] = inputs<int, int, int>();
        if ((!los[a] && !los[b])) {
            edges[a].push_back({b, t});
            edges[b].push_back({a, t});
        }
    }

    print(f());
}