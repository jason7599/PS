#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0, _n = n; i < _n; i++)
#define RANGE(i, s, e) for(int i = s, _e = e; i <= _e; i++)
#define REP(n) FOR(i, n)
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
template<typename T = int> T input() { T t; cin >> t; return t; }
template<typename T> T input(T& t) { cin >> t; return t; }
template<typename T, typename... Args> void input(T& t, Args&... args) { cin >> t; input(args...); }
template<typename T> void print(const T& t) { cout << t << '\n'; }
template<typename T, typename... Args> void print(const T& t, const Args&... args) { cout << t << ' '; print(args...); }
template<typename T> void upmax(T& v, const T& other) { v = max(v, other); }
template<typename T> void upmin(T& v, const T& other) { v = min(v, other); }

int n_holes, plank_len;
pii holes[10'000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(n_holes, plank_len);
    FOR(i, n_holes) {
        input(holes[i].fi, holes[i].se);
    }

    sort(holes, holes + n_holes);

    int ans = 0;
    for (int i = 0, e = 0; i < n_holes; i++) {
        if (holes[i].se > e) {
            int s = max(e, holes[i].fi);
            int t = (holes[i].se - s + plank_len - 1) / plank_len;
            ans += t;
            e = s + plank_len * t;
        }
    }

    print(ans);
}