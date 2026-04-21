#include <bits/stdc++.h>
#define FOR(i, n) for (ll i = 0, _n = n; i < _n; i++)
#define RANGE(i, s, e) for (ll i = s, _e = e; i <= _e; i++)
#define REP(n) for (ll _ = 0, _n = n; _ < _n; _++)
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
template<typename T, int C> array<T, C> inputs() { array<T, C> arr; for (T& t : arr) cin >> t; return arr; }
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF; }
template<typename T> T upmax(T& v, const T& other) { v = max(v, other); return v; }
template<typename T> T upmin(T& v, const T& other) { v = min(v, other); return v; }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n;
int arr[EE(6)];

bool check(int len, int cnt) {
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] < len) {
            return 0;
        }
        cnt -= arr[i] / len;
        if (cnt <= 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int x = input();
    FOR(i, input(n)) {
        input(arr[i]);
    }
    sort(arr, arr + n);

    int ans = 0;
    for (int l = 1, r = arr[n - 1]; l <= r;) {
        int m = (l + r) >> 1;
        if (check(m, x)) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    print(ans);
}