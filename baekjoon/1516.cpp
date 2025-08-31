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
template<typename T> T input(T& t) { cin >> t; return t; }
template<typename... Args> void input(Args&... args) { ((cin >> args), ...); }
template<typename... Args> tuple<Args...> inputs() { tuple<Args...> t; apply([](auto&... args){input(args...);}, t); return t; }
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF; }
template<typename T> T upmax(T& v, const T& other) { v = max(v, other); return v; }
template<typename T> T upmin(T& v, const T& other) { v = min(v, other); return v; }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n_nodes;
int costs[501];
vector<int> nexts[501];
vector<int> prevs[501];
bool vis[501];
int res[501];

void toposort(int node, stack<int>& stk) {
    vis[node] = 1;
    for (int nx : nexts[node]) {
        if (!vis[nx]) {
            toposort(nx, stk);
        }
    }
    stk.push(node);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    RANGE(i, 1, input(n_nodes)) {
        input(costs[i]);
        for (int x; input(x) != -1;) {
            nexts[x].push_back(i);
            prevs[i].push_back(x);
        }
    }

    stack<int> stk;
    RANGE(i, 1, n_nodes) {
        if (!vis[i]) {
            toposort(i, stk);
        }
    }

    for (; stk.size(); stk.pop()) {
        int node = stk.top();
        for (int p : prevs[node]) {
            upmax(res[node], res[p]);
        }
        res[node] += costs[node];
    }

    RANGE(i, 1, n_nodes) {
        print(res[i]);
    }
}