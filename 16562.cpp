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
template<typename T = int> T input() { T t; cin >> t; return t; }
template<typename T> T& input(T& t) { cin >> t; return t; }
template<typename... Args> void input(Args&... args) { ((cin >> args), ...); }
template<typename... Args> tuple<Args...> inputs() { tuple<Args...> t; apply([](auto&... args){input(args...);}, t); return t; }
template<typename T, int C> array<T, C> inputs() { array<T, C> arr; for (T& t : arr) cin >> t; return arr; }
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF; }
template<typename T> T& upmax(T& v, const T& other) { return v = max(v, other); }
template<typename T> T& upmin(T& v, const T& other) { return v = min(v, other); }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // drul

int roots[10'001];

int find_root(int n) {
    if (roots[n] == n) return n;
    return roots[n] = find_root(roots[n]);
}

bool make_union(int a, int b) {
    a = find_root(a);
    b = find_root(b);
    if (a == b) {
        return false;
    }

    roots[max(a, b)] = min(a, b);
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    auto [n_nodes, n_edges, weight_cap] = inputs<int, 3>();

    priority_queue<pii> pq; // <-cost, node>
    RANGE(n, 1, n_nodes) {
        roots[n] = n;
        pq.push({-input(), n});
    }

    int n_comps = n_nodes + 1;

    REP(n_edges) {
        if (make_union(input(), input())) {
            n_comps--;
        }
    }

    int weight_sm = 0;
    while (pq.size() && n_comps > 1) {
        int weight = -pq.top().fi;
        int to = pq.top().se;
        pq.pop();

        if (weight_sm + weight > weight_cap) break;

        if (make_union(0, to)) {
            weight_sm += weight;
            n_comps--;
        }
        
    }

    if (n_comps == 1) print(weight_sm);
    else print("Oh no");
}