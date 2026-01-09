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

vector<int> zfind(const string& text, const string& pattern) {
    const string s = pattern + '$' + text;

    const int N = s.size();
    vector<int> z(N, 0);
    vector<int> res;

    for (int i = 1, l = 0, r = 0; i < N; i++) {
        if (i <= r) {
            int k = i - l;
            z[i] = min(r - i + 1, z[k]);
        }

        while (i + z[i] < N && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }

        if (z[i] == pattern.length()) {
            res.push_back(i - pattern.length() + 1);
        }

        if (i + z[i] - 1 > r) { 
            l = i;
            r = i + z[i] - 1;
        }
    }

    return res;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);

    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);

    auto z = f(text, pattern);
    for (int i : z) {
        cout << i << ' ';
    }
    LF;
}