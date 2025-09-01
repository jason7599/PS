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
int roots[500'001];

int find_root(int a) {
    if (roots[a] != a) {
        roots[a] = find_root(roots[a]);
    }
    return roots[a];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    iota(roots + 1, roots + 1 + input(n_nodes), 1);

    int ans = 0;
    RANGE(t, 1, input()) {
        auto [a, b] = inputs<int, int>();
        if (ans) continue;

        a = find_root(a);
        b = find_root(b);

        if (a == b) {
            ans = t;
        } else {
            roots[max(a, b)] = min(a, b);
        }
    }

    print(ans);
}