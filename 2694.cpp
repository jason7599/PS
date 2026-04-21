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

int n, arr[10'000];

bool chk(int x) {
    int sm = 0;
    FOR(i, n) {
        sm += arr[i];
        if (sm == x) {
            sm = 0;
        } else if (sm > x) {
            return 0;
        }
    }
    return !sm;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    REP(input()) {
        int mx = 0;
        int sm = 0;
        FOR(i, input(n)) {
            sm += input(arr[i]);
            upmax(mx, arr[i]);
        }

        vector<int> divs;
        for (int i = 1; i * i <= sm; i++) {
            if (sm % i == 0) {
                if (i >= mx) {
                    divs.push_back(i);
                }
                if (i != sm / i && sm / i >= mx) {
                    divs.push_back(sm / i);
                }
            }
        }

        sort(divs.begin(), divs.end());
        
        int ans = sm;
        for (int d : divs) {
            if (chk(d)) {
                ans = d;
                break;
            }
        }

        print(ans);
    }
}