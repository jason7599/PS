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

char& dp(const array<int, 6>& used) {
    static char memo[5][5][5][5][5][5];
    auto [a, b, c, d, e, f] = used;
    return memo[a][b][c][d][e][f];
}

bool f(const array<int, 6>& used, int sm) {
    char& res = dp(used);
    if (res) {
        return res == 1;
    }

    auto cpy = used;
    FOR(i, 6) {
        if (used[i] != 4 && sm + (i + 1) <= 31) {
            cpy[i]++;
            if (!f(cpy, sm + (i + 1))) {
                res = 1;
                return 1;
            }
            cpy[i]--;
        }
    }

    res = -1;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    for (string s; cin >> s;) {
        array<int, 6> used{};
        int sm = 0;
        for (char c : s) {
            int i = c - '0';
            sm += i;
            used[i - 1]++;
        }
        print(s, (f(used, sm) ^ (s.length() % 2) ? 'A' : 'B'));
    }
}