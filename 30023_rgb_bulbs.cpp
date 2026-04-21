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

int n, arr[100'000];
int shift[100'000];

int cost(int a, int b) {
    return a <= b ? b - a : b + 3 - a;
}

int f(int c) {
    fill(&shift[0], &shift[n], 0);

    int res = 0;
    FOR(i, n - 2) {
        int t = (arr[i] + shift[i]) % 3;
        if (t != c) {
            res += cost(t, c);
            RANGE(j, i, i + 2) {
                shift[j] += cost(t, c);
            }
        }
    }

    RANGE(i, n - 2, n - 1) {
        if ((arr[i] + shift[i]) % 3 != c) {
            return -1;    
        }
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string rgb = "RGB";
    FOR(i, input(n)) {
        arr[i] = rgb.find(input<char>());
    }

    int ans = INT_MAX;
    FOR(c, 3) {
        int t = f(c);
        if (t != -1) {
            upmin(ans, t);
        }
    }

    print(ans == INT_MAX ? -1 : ans);
}