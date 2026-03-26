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
template<typename T = int> T input() { T t; cin >> t; return t; }
template<typename T> T& input(T& t) { cin >> t; return t; }
template<typename... Args> void input(Args&... args) { ((cin >> args), ...); }
template<typename... Args> tuple<Args...> inputs() { tuple<Args...> t; apply([](auto&... args){input(args...);}, t); return t; }
template<typename T, int C> array<T, C> inputs() { array<T, C> arr; for (T& t : arr) cin >> t; return arr; }
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF; }
template<typename T> T& upmax(T& v, const T& other) { return v = max(v, other); }
template<typename T> T& upmin(T& v, const T& other) { return v = min(v, other); }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // drul

int mem[101][3]; // <i, k>

// max removeable length
int f(const string &s, int k, int i) {
    if (!k || i >= s.length()) return 0;

    int &res = mem[i][k];
    if (res != -1) return res; 

    res = 0;
    for (; i < s.length() - 1; i++) {
        if (s[i] == 'X') continue;
        for (int j = i + 1; j < s.length(); j++) {
            if (s[i] == s[j]) {
                upmax(res, (j - i + 1) + f(s, k - 1, j + 1));
            }
        }
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    auto [n, k, s] = inputs<int, int, string>();
    memset(mem, -1, sizeof mem);
    print(s.length() - f(s, k, 0));
}