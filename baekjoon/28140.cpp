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

vector<int> rs, bs;

bool find(int l, int r, int ans[4]) {
    int li = lower_bound(rs.begin(), rs.end(), l) - rs.begin();
    if (li >= (int)rs.size() - 1 || rs[li + 1] >= r - 1) {
        return 0;
    }

    int ri = upper_bound(bs.begin(), bs.end(), rs[li + 1]) - bs.begin();
    if (ri >= (int)bs.size() - 1 || bs[ri + 1] > r) {
        return 0;
    }

    ans[0] = rs[li];
    ans[1] = rs[li + 1];
    ans[2] = bs[ri];
    ans[3] = bs[ri + 1];

    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    auto [n, k] = inputs<int, 2>();

    FOR(i, n) {
        char c = input<char>();
        if (c == 'R') rs.push_back(i);
        else if (c == 'B') bs.push_back(i);
    }

    int ans[4];
    REP(k) {
        auto [l, r] = inputs<int, 2>();
        if (find(l, r, ans)) {
            for (int i : ans) {
                cout << i << ' ';
            }
            LF;
        } else {
            print(-1);
        }
    }
}