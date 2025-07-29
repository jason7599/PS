#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0, __n = n; i < __n; i++)
#define RANGE(i, s, e) for(int i = s, __e = e; i <= __e; i++)
#define REP(n) FOR(__, n)
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
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

const int VALS[4] = {1, 5, 10, 25};

int cnts[4];
pii dp[10'001][4]; // <total_cnt, this_cnt>

pii f(int x, int i) {
    if (!x) {
        return {0, 0};
    }

    if (i == 4) {
        return {-1, 0};
    }

    pii& res = dp[x][i];
    if (res.fi) {
        return res;
    }

    for (int cnt = 0; cnt <= cnts[i] && VALS[i] * cnt <= x; cnt++) {
        pii t = f(x - VALS[i] * cnt, i + 1);
        if (t.fi != -1) {
            if (res.fi < cnt + t.fi) {
                res = {cnt + t.fi, cnt};
            }
        }
    }

    if (!res.fi) {
        res.fi = -1;
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int x = input();
    FOR(i, 4) {
        input(cnts[i]);
    }

    if (f(x, 0).fi == -1) {
        print(0, 0, 0, 0);
    } else {
        for (int i = 0, v = x; i < 4; i++) {
            cout << dp[v][i].se << ' ';
            v -= dp[v][i].se * VALS[i];
        }
        cout << '\n';
    }
}