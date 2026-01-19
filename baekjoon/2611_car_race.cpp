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

int n_nodes;
vector<pii> edges[1001]; // [0]: dummy node for -> 1
pii dmap[1001]; // <max_score, prev>

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(n_nodes);
    REP(input()) {
        auto [a, b, d] = inputs<int, 3>();
        edges[a].push_back({(b == 1 ? 0 : b), d});
    }

    priority_queue<pii> pq;
    pq.push({0, 1});

    while (pq.size()) {
        auto [score, node] = pq.top();
        pq.pop();

        if (dmap[node].fi > score) continue;

        for (const auto& [nxt, d] : edges[node]) {
            if (dmap[nxt].fi < score + d) {
                dmap[nxt] = {score + d, node};
                pq.push({score + d, nxt});
            }
        }
    }

    print(dmap[0].fi);

    stack<int> path;
    for (int n = dmap[0].se; n; n = dmap[n].se) {
        path.push(n);
    }

    while (path.size()) {
        cout << path.top() << ' ';
        path.pop();
    }
    print(1);
}