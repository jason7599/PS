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

int n;
ll arr[250'000];
ll dp[250'000][2][2];

ll f(int i, bool prev, bool init) {
    if (i == n) return 0;

    ll& res = dp[i][prev][init];
    if (res != -1) return res;

    if (i == 0) {
        if (init) {
            return res = 1 + f(1, 1, 1);
        } else {
            return res = arr[0] + f(1, 0, 0);
        }
    }

    if (arr[i] || prev || (init && i == n - 1)) {
        return res = arr[i] + f(i + 1, 0, init);
    }

    return res = max(
        1 + f(i + 1, 1, init),
        f(i + 1, 0, init)  
    );
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    FOR(i, input(n)) {
        input(arr[i]);
        fill(dp[i][0], dp[i][0] + 4, -1);
    }

    print(max(f(0, 0, 0), f(0, 0, 1)));
}