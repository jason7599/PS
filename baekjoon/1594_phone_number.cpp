#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0, __n = n; i < __n; i++)
#define RANGE(i, s, e) for(int i = s, __e = e; i <= __e; i++)
#define REP(n) FOR(__, n)
#define LF {cout << '\n';}
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
template<typename T = int> T input() { T t; cin >> t; return t; }
template<typename T> T input(T& t) { cin >> t; return t; }
template<typename... Args> void input(Args&... args) { ((cin >> args), ...); }
template<typename... Args> tuple<Args...> inputs() { tuple<Args...> t; apply([](auto&... args){input(args...);}, t); return t; }
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF }
template<typename T> T upmax(T& v, const T& other) { v = max(v, other); return v; }
template<typename T> T upmin(T& v, const T& other) { v = min(v, other); return v; }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int dp[1000];
int spl[1000];

int ev(string& s, int i, int l) {
    unordered_set<int> set(s.begin() + i, s.begin() + i + l);
    if (set.size() == 1) {
        return 2;
    }
    if (set.size() == 2 && l == 3) {
        return 1;
    }
    return 0;
}

int f(string& s, int i) {
    if (i == s.length()) {
        return 0;
    }

    int& res = dp[i];
    if (res != -1) {
        return res;
    }

    int t = s.length() - i;

    int res2 = (t == 3) ? 
        -1 : ev(s, i, 2) + f(s, i + 2);
    int res3 = (t == 2 || t == 4) ? 
        -1 : ev(s, i, 3) + f(s, i + 3);

    spl[i] = res3 > res2 ? 3 : 2;
    return res = max(res2, res3);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    auto s = input<string>();
    fill(&dp[0], &dp[s.length()], -1);

    f(s, 0);
    for (int b = 0; b < s.length();) {
        cout << s.substr(b, spl[b]);
        b += spl[b];
        cout << (b < s.length() ? '-' : '\n');
    }
}