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

bool vis[(int)1e6 + 1];

int f(int n, int a, int b) {
    queue<int> q;

    auto push = [&](int x) {
        if (x >= 0 && !vis[x]) {
            vis[x] = 1;
            q.push(x);
        }
    };

    push(n);

    for (int t = 0, q_sz; (q_sz = q.size()); t++) {
        while (q_sz--) {
            int x = q.front(); q.pop();
            if (!x) return t;
            for (int nxt : {x - 1, x - 1 - a, x - 1 - b}) push(nxt);
        }
    }

    assert(0);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    auto [n, a, b] = inputs<int, 3>();
    print(f(n, a, b));
}