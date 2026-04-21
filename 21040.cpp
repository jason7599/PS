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

int n, k;
int arr[100'000];

bool f(int min_diff) {
    int cnt = 1;
    int prv = arr[0];

    for (int i = 1; i < n; i++) {
        if (k - cnt > n - i) return 0;
        if (arr[i] - prv >= min_diff) {
            if (++cnt == k) return 1;
            prv = arr[i];
        }
    }

    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(n, k);
    FOR(i, n) input(arr[i]);
    sort(arr, arr + n);
    
    int ans;
    for (int l = 0, r = arr[n - 1] - arr[0]; l <= r;) {
        int m = (l + r) / 2;
        if (f(m)) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    print(ans);
}