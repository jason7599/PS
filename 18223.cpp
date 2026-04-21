#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0, _n = n; i < _n; i++)
#define RANGE(i, s, e) for (int i = s, _e = e; i <= _e; i++)
#define REP(n) for (int _ = 0, _n = n; _ < _n; _++)
#define DBG(x) cerr << #x << " = " << x << '\n'
using namespace std;
using pii = pair<int, int>;
template<typename T = int> T input() { T t; cin >> t; return t; }
template<typename T> T& input(T& t) { cin >> t; return t; }
template<typename... Args> void input(Args&... args) { ((cin >> args), ...); }
template<typename... Args> tuple<Args...> inputs() { tuple<Args...> t; apply([](auto&... args){input(args...);}, t); return t; }
template<typename T, int C> array<T, C> inputs() { array<T, C> arr; for (T& t : arr) cin >> t; return arr; }
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); cout << '\n'; }
template<typename T> T& upmax(T& v, const T& other) { return v = max(v, other); }
template<typename T> T& upmin(T& v, const T& other) { return v = min(v, other); }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // drul

vector<pii> edges[5001];
vector<int> prevs[5001];
int dmap[5001];

bool find(int node, int target) {
    if (node == target) return true;
    if (node == 1) return false;

    for (int p : prevs[node]) {
        if (find(p, target)) return true;
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    auto [n_nodes, n_edges, target] = inputs<int, 3>();
    REP(n_edges) {
        auto [a, b, d] = inputs<int, 3>();
        edges[a].push_back({b, d});
        edges[b].push_back({a, d});
        
        dmap[a] = dmap[b] = INT_MAX;
    }

    priority_queue<pii> pq; // <-cost, node>
    pq.push({0, 1});
    dmap[1] = 0;

    while (pq.size()) {
        int cur_d = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dmap[cur] < cur_d) continue;

        for (const auto &[nxt, d] : edges[cur]) {
            int nxt_d = cur_d + d;
            if (dmap[nxt] > nxt_d) {
                dmap[nxt] = nxt_d;
                pq.push({-nxt_d, nxt});

                prevs[nxt].clear();
                prevs[nxt].push_back(cur);
            } else if (dmap[nxt] == nxt_d) {
                prevs[nxt].push_back(cur);
            }
        }
    }

    print(find(n_nodes, target) ? "SAVE HIM" : "GOOD BYE");
}