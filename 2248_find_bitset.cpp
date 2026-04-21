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

ll dp[32][32];

ll f(int len, int cnt) {
    if (!cnt) {
        return 1;
    }

    ll& res = dp[len][cnt];
    if (res) {
        return res;
    }

    if (len == cnt) {
        return res = 1;
    }

    return res = f(len - 1, cnt) + f(len - 1, cnt - 1);
}

ll ff(int len, int cnt) {
    ll res = 0;
    for (int c = 0; c <= min(len, cnt); c++) {
        res += f(len, c);
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    auto [len, mx, k] = inputs<ll, 3>();

    for (; len;) {
        ll t = ff(len - 1, mx); // 여기서 0을 안 쓴 경우의 수
        if (k <= t) {
            cout << 0;
        } else {
            cout << 1;
            k -= t;
            mx--;
        }
        len--;
    } 
    LF;
}