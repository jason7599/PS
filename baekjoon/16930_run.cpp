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

int g_h, g_w, mx_moves;
bool walls[1000][1000];
bool vis[1000][1000][4];

array<int, 2> get_side_dirs(int dir) {
    return {(dir + 3) % 4, (dir + 1) % 4};
}

int op_dir(int d) {
    if (d < 2) {
        return d + 2;
    }
    return d - 2;
}

pii apply_dir(pii pos, int d) {
    return {pos.fi + DIRS[d].fi, pos.se + DIRS[d].se};
}

bool is_oob(pii pos) {
    return pos.fi < 0 || pos.fi >= g_h || pos.se < 0 || pos.se >= g_w;
}

int solve(int s_y, int s_x, int e_y, int e_x) {
    queue<pair<pii, int>> q;
    FOR(d, 4) {
        q.push({{s_y, s_x}, d});
        vis[s_y][s_x][d] = 1;
    }

    for (int q_size, n_moves = 1; (q_size = q.size()); n_moves++) {
        while (q_size--) {
            pii pos = q.front().fi;
            int d = q.front().se;
            q.pop();

            auto side_ds = get_side_dirs(d);

            for (int moves = 0; moves <= mx_moves && !is_oob(pos) && !walls[pos.fi][pos.se]; moves++, pos = apply_dir(pos, d)) {
                const auto [y, x] = pos;

                if (vis[y][x][d] || vis[y][d][op_dir(d)]) {
                    continue;
                }
                vis[y][x][d] = 1;
                vis[y][x][op_dir(d)] = 1;

                if (y == e_y && x == e_x) {
                    return n_moves;
                }

                if (moves == mx_moves) {
                    q.push({pos, d});
                }

                for (int side : side_ds) {
                    pii t = apply_dir(pos, side);
                    if (!is_oob(t) && !walls[t.fi][t.se] && !vis[y][x][side]) {
                        vis[y][x][side] = 1;
                        q.push({pos, side});
                    }
                }
            }
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(g_h, g_w, mx_moves);
    FOR(y, g_h) {
        FOR(x, g_w) {
            walls[y][x] = input<char>() == '#';
        }
    }

    auto [s_y, s_x, e_y, e_x] = inputs<int, int, int, int>();

    print(solve(--s_y, --s_x, --e_y, --e_x));
}