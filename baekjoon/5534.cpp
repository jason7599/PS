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

bool check(string& targ, string& s) {
    for (int i, b = 0; 
        b < s.length()
        && (i = s.find(targ[0], b)) != -1
        && i + targ.length() <= s.length();
        b = i + 1) 
    {
        for (int ni, nb = i + 1;
            nb < s.length()
            && (ni = s.find(targ[1], nb)) != -1
            && i + (ni - i) * (targ.length() - 1) <= s.length();
            nb = ni + 1)
        {
            bool good = 1;
            for (int ti = 2; ti < targ.length(); ti++) {
                if (targ[ti] != s[i + (ni - i) * ti]) {
                    good = 0;
                    break;
                }
            }
            if (good) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    auto [n, targ] = inputs<int, string>();
    vector<string> words(n);
    for (auto& s : words) {
        input(s);
    }

    int ans = 0;
    for (auto& s : words) {
        ans += check(targ, s);
    }

    print(ans);
}