#include <bits/stdc++.h>
#define FOR(i, N) for (int i = 0, _n = N; i < _n; i++)
#define RANGE(i, s, e) for (int i = s, _e = e; i <= _e; i++)
#define REP(N) for (int _ = 0, _n = N; _ < _n; _++)
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

int N, M;
int arr[100'000];

bool test(int cap) { // cap = bluray 최대 길이
    int t = 0; // # group
    int sm = 0;
    FOR(i, N) {
        if (arr[i] > cap) {
            return 0;
        }
        sm += arr[i];
        if (sm > cap) {
            if (++t == M) {
                return 0;
            }
            sm = arr[i];
        }
    }
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(N, M);
    FOR(i, N) {
        input(arr[i]);
    }

    int ans;
    for (int l = 0, r = EE(9); l <= r;) {
        int m = (l + r) >> 1;
        if (test(m)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    print(ans);
}