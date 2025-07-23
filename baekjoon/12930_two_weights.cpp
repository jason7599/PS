#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0, _n = n; i < _n; i++)
#define RANGE(i, s, e) for(int i = s, _e = e; i <= _e; i++)
#define REP(n) FOR(i, n)
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
template<typename T> T input() { T t; cin >> t; return t; } int input() { return input<int>(); }
template<typename T> T input(T& t) { cin >> t; return t; }
template<typename T, typename... Args> void input(T& t, Args&... args) { cin >> t; input(args...); }
template<typename T> void print(const T& t) { cout << t << '\n'; }
template<typename T, typename... Args> void print(const T& t, const Args&... args) { cout << t << ' '; print(args...); }

int n_nodes, weights[2][20][20];
int dmap[20];

int solve() {
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(n_nodes);
    FOR(i, 2) {
        FOR(y, n_nodes) {
            FOR(x, n_nodes) {
                char c;
                input(c);
                if (c != '.') {
                    weights[i][y][x] = c - '0';
                }
            }
        }
    }

    print(solve());
}