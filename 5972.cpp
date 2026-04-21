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

int n_nodes;
int dmap[50'001];
vector<pii> edges[50'001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(n_nodes);
    REP(input()) {
        auto [a, b, c] = inputs<int, 3>();
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
        dmap[a] = dmap[b] = INT_MAX;
    }

    priority_queue<pii> pq;
    pq.push({0, 1});
    dmap[1] = 0;

    while (pq.size()) {
        int cur = pq.top().se;
        int cur_d = -pq.top().fi;
        pq.pop();

        if (dmap[cur] < cur_d) {
            continue;
        }

        for (const auto& [nxt, d] : edges[cur]) {
            int nxt_d = cur_d + d;
            if (dmap[nxt] > nxt_d) {
                dmap[nxt] = nxt_d;
                pq.push({-nxt_d, nxt});
            }
        }
    }

    print(dmap[n_nodes]);
}