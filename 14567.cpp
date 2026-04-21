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

vector<int> edges[1001];
bool vis[1001];
int res[1001];

void toposort(int n, stack<int> &stk) {
    vis[n] = true;
    for (int nxt : edges[n]) {
        if (!vis[nxt]) {
            toposort(nxt, stk);
        }
    } 
    stk.push(n);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_nodes = input();
    REP(input()) {
        auto [a, b] = inputs<int, 2>();
        edges[a].push_back(b);
    }

    stack<int> topo;
    RANGE(n, 1, n_nodes) {
        if (!vis[n]) {
            toposort(n, topo);
        }
    }

    for (; topo.size(); topo.pop()) {
        int n = topo.top();
        if (!res[n]) { // unmarked; meaning no immediate prereqs
            res[n] = 1;
        }

        for (int nxt : edges[n]) {
            upmax(res[nxt], res[n] + 1);
        }
    }

    RANGE(n, 1, n_nodes) {
        cout << res[n] << ' ';
    }
    print();
}