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

int n_swaps;
pair<pii, int> swaps[10];

bool is_sorted(string& s) {
    FOR(i, s.length() - 1) {
        if (s[i] > s[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int solve(string& start) {
    unordered_map<string, int> dmap;
    priority_queue<pair<int, string>> pq;

    dmap[start] = 0;
    pq.push({0, start});

    int ans = INT_MAX;

    while (pq.size()) {
        string str = pq.top().se;
        int d = -pq.top().fi;
        pq.pop();

        if (dmap[str] < d) {
            continue;
        }

        if (is_sorted(str)) {
            upmin(ans, d);
        } 

        FOR(i, n_swaps) {
            string nxt = str;
            swap(nxt[swaps[i].fi.fi], nxt[swaps[i].fi.se]);

            int nd = d + swaps[i].se;
            if (!dmap.count(nxt) || dmap[nxt] > nd) {
                dmap[nxt] = nd;
                pq.push({-nd, nxt});
            }
        }
    }

    return ans == INT_MAX ? -1 : ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string start;
    start.resize(input());
    for (char& c : start) {
        c = input() - 1 + '0';
    }

    FOR(i, input(n_swaps)) {
        auto [l, r, c] = inputs<int, 3>();
        swaps[i] = {{--l, --r}, c};
    }

    print(solve(start));
}