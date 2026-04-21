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

bool vis[100'000];

int f(int src, int dst, int max_turns) {
    if (src == dst) {
        return 0;
    }

    queue<int> q({src});
    vis[src] = 1;

    auto push = [&](int x) {
        if (vis[x]) {
            return false;
        }
        vis[x] = 1;
        q.push(x);
        return x == dst;
    };

    for (int t = 1, q_size; (q_size = q.size()) && t <= max_turns; t++) {
        REP(q_size) {
            int cur = q.front();
            q.pop();

            if (cur < 99'999) {
                if (push(cur + 1)) {
                    return t;
                }
            }

            if (cur && cur * 2 <= 99'999) {
                int nxt = cur * 2;
                int d = 1;
                for (; nxt / (d * 10); d *= 10);

                if (push(nxt - d)) {
                    return t;
                }
            }
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    auto [src, max_turns, dst] = inputs<int, int, int>();

    int t = f(src, dst, max_turns);
    if (t == -1) {
        print("ANG");
    } else {
        print(t);
    }
}