#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define RANGE(i, s, e) for(int i = s; i <= e; i++)
#define REP(n) FOR(i, n)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
template<typename T> T input() { T t; cin >> t; return t; }
template<typename T> void input(T& t) { cin >> t; }
template<typename T> void print(const T& t) { cout << t << '\n'; }
template<typename T, typename... Args> void input(T& t, Args&... args) { cin >> t; input(args...); }
template<typename T, typename... Args> void print(const T& t, const Args&... args) { cout << t << ' '; print(args...);}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_obs, n_cmds;
    input(n_obs, n_cmds);

    set<pii> obs;
    REP(n_obs) {
        int x, y;
        input(x, y);
        obs.insert({x, y});
    }

    int x = 0, y = 0;
    REP(n_cmds) {
        char c;
        input(c);
        int nx = x, ny = y;
        switch (c) {
        case 'U': ny++; break;
        case 'D': ny--; break;
        case 'R': nx++; break;
        case 'L': nx--;
        }
        if (!obs.count({nx, ny})) {
            x = nx, y = ny;
        }
    }

    print(x, y);
}