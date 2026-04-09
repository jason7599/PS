#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0, _n = n; i < _n; i++)
#define RANGE(i, s, e) for (int i = s, _e = e; i <= _e; i++)
#define REP(n) for (int _ = 0, _n = n; _ < _n; _++)
#define DBG(x) cerr << #x << " = " << x << '\n'
using namespace std;
using pii = pair<int, int>;
template<typename T = int> T input() { T t; cin >> t; return t; }
template<typename T> T& input(T& t) { cin >> t; return t; }
template<typename... Args> void input(Args&... args) { ((cin >> args), ...); }
template<typename... Args> tuple<Args...> inputs() { tuple<Args...> t; apply([](auto&... args){input(args...);}, t); return t; }
template<typename T, int C> array<T, C> inputs() { array<T, C> arr; for (T& t : arr) cin >> t; return arr; }
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); cout << '\n'; }
template<typename T> T& upmax(T& v, const T& other) { return v = max(v, other); }
template<typename T> T& upmin(T& v, const T& other) { return v = min(v, other); }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // drul

const int G_WALL = -1;
const int G_EMPTY = -2;

int g_h, g_w;
int n_items;
int grid[50][50];
bool vis[50][50][1 << 5];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(g_w, g_h);
    pii src, dst;
    FOR(y, g_h) {
        FOR(x, g_w) {
            switch (input<char>()) {
                case '#': {
                    grid[y][x] = G_WALL;
                    break;
                }
                case '.': {
                    grid[y][x] = G_EMPTY;
                    break;
                }
                case 'S': {
                    src = {y, x};
                    grid[y][x] = G_EMPTY;
                    break;
                }
                case 'E': {
                    dst = {y, x};
                    grid[y][x] = G_EMPTY;
                    break;
                }
                case 'X': {
                    grid[y][x] = n_items++;
                    break;
                }
            }
        }
    }

    queue<pair<pii, int>> q({{src, 0}});
    vis[src.first][src.second][0] = true;
    
    int ans = 0;
    for (;; ans++) {
        bool finish = false;

        int q_sz = q.size();
        REP(q_sz) {
            auto [y, x] = q.front().first;
            int msk = q.front().second;
            q.pop();

            if (make_pair(y, x) == dst && msk == (1 << n_items) - 1) {
                finish = true;
                break;
            }

            for (const auto &[dy, dx] : DIRS) {
                int ny = y + dy;
                int nx = x + dx;

                if (ny < 0 || ny >= g_h || nx < 0 || nx >= g_w || grid[ny][nx] == G_WALL) {
                    continue;
                }

                int nmsk = msk;
                if (grid[ny][nx] != G_EMPTY) {
                    nmsk |= (1 << grid[ny][nx]);
                }

                if (!vis[ny][nx][nmsk]) {
                    vis[ny][nx][nmsk] = true;
                    q.push({{ny, nx}, nmsk});
                }
            }
        }

        if (finish) break;
    }

    print(ans);
}