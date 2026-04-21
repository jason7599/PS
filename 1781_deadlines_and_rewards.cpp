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

int n;
pii arr[200'000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    FOR(i, input(n)) {
        input(arr[i].fi, arr[i].se);
    }

    sort(arr, arr + n, [](pii& lhs, pii& rhs) {
        if (lhs.fi == rhs.fi) {
            return lhs.se > rhs.se;
        }
        return lhs.fi < rhs.fi;
    });

    priority_queue<int> pq; // min heap for rewards
    int ans = 0;

    FOR(i, n) {
        if (arr[i].fi > pq.size()) {
            pq.push(-arr[i].se);        
            ans += arr[i].se;
        } else if (arr[i].fi == pq.size()) {
            if (arr[i].se > -pq.top()) {
                ans -= -pq.top();
                pq.pop();
                pq.push(-arr[i].se);
                ans += arr[i].se;
            }
        } else { // 
            assert(0);
        }
    }

    print(ans);
}