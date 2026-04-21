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

const string pkht = "PKHT";

int cnts[4];
bool vis[4][13];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    auto s = input<string>();
    for (int i = 0; i < s.length(); i += 3) {
        int t = pkht.find(s[i]);
        int v = 10 * (s[i + 1] == '1') + s[i + 2] - '0' - 1;
        if (vis[t][v]) {
            print("GRESKA");
            return 0;
        }

        vis[t][v] = 1;
        cnts[t]++;
    }

    FOR(i, 4) {
        cout << 13 - cnts[i] << ' ';
    }
    LF;
}