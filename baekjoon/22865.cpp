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

vector<pii> edges[100'001];
int dmap[100'001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_nodes = input();
    auto srcs = inputs<int, 3>();
    
    REP(input()) {
        auto [a, b, d] = inputs<int, 3>();
        edges[a].push_back({b, d});
        edges[b].push_back({a, d});
        dmap[a] = dmap[b] = INT_MAX;
    }

    priority_queue<pii> pq;
    for (int s : srcs) {
        pq.push({dmap[s] = 0, s});
    }

    int ans = 0;
    while (pq.size()) {
        int cur_d = -pq.top().fi;
        int cur = pq.top().se;
        pq.pop();

        if (cur_d > dmap[cur]) continue;

        if (cur_d > dmap[ans] || (cur_d == dmap[ans] && ans < cur)) {
            ans = cur;
        }

        for (const auto& [nxt, d] : edges[cur]) {
            int nxt_d = cur_d + d;
            if (dmap[nxt] > nxt_d) {
                dmap[nxt] = nxt_d;
                pq.push({-nxt_d, nxt});
            }
        }
    }

    print(ans);
}