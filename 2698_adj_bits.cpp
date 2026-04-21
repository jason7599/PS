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

int dp[101][101][2];

int f(int len, int cnt, bool prev) {

    if (!len || cnt < 0) {
        return !cnt;
    }

    if (len < cnt + 1) {
        return 0;
    }

    int& res = dp[len][cnt][prev];

    if (res) {
        return res;
    }

    res = f(len - 1, cnt, 0);
    if (prev) {
        res += f(len - 1, cnt - 1, 1);
    } else {
        res += f(len - 1, cnt, 1);
    }

    return res;

    /**
     * placing 0: only if it does not lead to 
     *  insufficient remaining len for remaining cnt.
     * 
     * insufficient len for cnt formula?
     * => For cnt c, must have at least len c + 1
     *  so len >= cnt + 1 should hold.
     * 
     * placing 1: only if it does not result in a 
     *  new pair when cnt = 0
     * 
    */
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    REP(input()) {
        auto [len, cnt] = inputs<int, 2>();
        print(f(len, cnt, 0));
    }
}