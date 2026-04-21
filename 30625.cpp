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

const int MOD = 1e9 + 7;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    auto [n, m] = inputs<int, 2>();

    int n_same = 0;
    REP(n) {
        auto [a, b] = inputs<int, 2>();
        n_same += !b;
    }
    int n_diff = n - n_same;

    int ans = 0;
    int bitch = 1;
    REP(n_diff - 1) {
        bitch = (bitch * (m - 1)) % MOD;
    }
    int bbitch = (bitch * (m - 1)) % MOD;
    
    // case 1: no mistakes
    // (m - 1) ^ n_diff
    if (!(m == 1 && n_diff)) {
        ans = bbitch;
    }

    // case 2: 1 diff instead of same
    // n_same * (m - 1) * ((m - 1) ^ n_diff)
    // = n_same * ((m - 1) ^ n_diff) 
    if (n_same) {
        ans = (ans + (((n_same * bbitch) % MOD) * (m - 1)) % MOD) % MOD;
    }
    
    // case 3: 1 same instead of diff
    // n_diff * ((m - 1) ^ (n_diff - 1))
    if (n_diff) {
        ans = (ans + n_diff * bitch) % MOD;
    }

    print(ans);
}