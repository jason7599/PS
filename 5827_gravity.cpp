#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define RANGE(i, s, e) for(int i = s; i <= e; i++)
#define REP(n) FOR(i, n)
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
template<typename T> T input() { T t; cin >> t; return t; }
template<typename T> void input(T& t) { cin >> t; }
template<typename T> void print(const T& t) { cout << t << '\n'; }
template<typename T, typename... Args> void input(T& t, Args&... args) { cin >> t; input(args...); }
template<typename T, typename... Args> void print(const T& t, const Args&... args) { cout << t << ' '; print(args...); }

int g_h, g_w;
bool grid[500][500];
bool vis[500][500][2];

int f(pii start, pii dest) {
    queue<pii> q({start});
    vis[start.fi][start.se][0] = 1;

    for (int q_size, n_flips = 0; (q_size = q.size()); n_flips++) {
        bool is_flipped = n_flips % 2;
        REP(q_size) {

        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(g_h, g_w);
    pii start, dest;
    FOR(y, g_h) {
        FOR(x, g_w) {
            char c;
            input(c);
            if (c == 'C') {
                start = {y, x};
            } else if (c == 'D') {
                dest = {y, x};
            } else {
                grid[y][x] = c == '#';
            }
        }
    }
}