#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0, _n = n; i < _n; i++)
#define RANGE(i, s, e) for (int i = s, _e = e; i <= _e; i++)
#define REP(n) for (int _ = 0, _n = n; _ < _n; _++)
#define STR(x) #x
#define DBG(x) cerr << #x << " = " << x << '\n'
#define EE(p) (ll)(1e##p)
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

/*
each vacant cluster grows every day
the 2 swans can meet => their respective clusters are joined

1. label each vacant cluster & collect tiles that will melt next turn
2. melting process:
    iterate tiles, collect the next tiles that will melt.
    make union adjacent vacant cluster ids.
*/

const int G_VAC_UNVIS = -3; // init purposes - vacant tiles which have not been labeled yet.
const int G_ICE_UNVIS = -2; // ice tiles that have not yet been pushed to nxt_melt_q
const int G_ICE_VIS = -1; // ice tiles that have been pushed to nxt_melt_q

int g_h, g_w;
int grid[1500][1500]; // x >= 0 for vacant of cluster id x

vector<int> vac_roots;
queue<pii> nxt_melt_q;

int get_vac_root(int id) {
    if (vac_roots[id] != id) {
        vac_roots[id] = get_vac_root(vac_roots[id]);
    }
    return vac_roots[id];
}

int make_vac_union(int id0, int id1) {
    id0 = get_vac_root(id0);
    id1 = get_vac_root(id1);
    return vac_roots[max(id0, id1)] = min(id0, id1);
}

bool is_oob(int y, int x) {
    return y < 0 || y >= g_h || x < 0 || x >= g_w;
}

void init_vac(int y, int x, int id) {
    grid[y][x] = id;
    for (const auto& [dy, dx] : DIRS) {
        int ny = y + dy;
        int nx = x + dx;
        if (!is_oob(ny, nx)) {
            if (grid[ny][nx] == G_VAC_UNVIS) {
                init_vac(ny, nx, id);
            } else if (grid[ny][nx] == G_ICE_UNVIS) {
                nxt_melt_q.push({ny, nx});
                grid[ny][nx] = G_ICE_VIS;
            }
        }
    }
}

void melt() {
    REP(nxt_melt_q.size()) {
        int y = nxt_melt_q.front().fi;
        int x = nxt_melt_q.front().se;
        nxt_melt_q.pop();

        int root = -1;
        for (const auto& [dy, dx] : DIRS) {
            int ny = y + dy;
            int nx = x + dx;

            if (!is_oob(ny, nx)) {
                if (grid[ny][nx] >= 0) { // vac cluster
                    if (root == -1) {
                        root = grid[ny][nx];
                    } else {
                        root = make_vac_union(root, grid[ny][nx]);
                    }
                } else if (grid[ny][nx] == G_ICE_UNVIS) {
                    nxt_melt_q.push({ny, nx});
                    grid[ny][nx] = G_ICE_VIS;
                }
            }
        }

        grid[y][x] = root;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(g_h, g_w);

    pii src{-1, 0}, dst;

    FOR(y, g_h) {
        FOR(x, g_w) {
            switch (input<char>()) {
            case 'L':
                if (src.fi == -1) {
                    src = {y, x};
                } else {
                    dst = {y, x};
                }
            case '.':
                grid[y][x] = G_VAC_UNVIS;
                break;
            default: // ice
                grid[y][x] = G_ICE_UNVIS;
            }
        }
    }

    int n_vac_clusters = 0;
    FOR(y, g_h) {
        FOR(x, g_w) {
            if (grid[y][x] == G_VAC_UNVIS) {
                vac_roots.push_back(n_vac_clusters); // iota
                init_vac(y, x, n_vac_clusters++);
            }
        }
    }

    int ans = 0;
    for (; get_vac_root(grid[src.fi][src.se]) != get_vac_root(grid[dst.fi][dst.se]); melt(), ans++);

    print(ans);
}