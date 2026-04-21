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

int gh, gw;
int grid[501][501];
int dmap[501][501];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(gh, gw);
    auto [sy, sx] = inputs<int, 2>();
    auto [c_asc, c_dsc, h_lim] = inputs<int, 3>();

    int ey = 0, ex = 0;
    RANGE(y, 1, gh) {
        RANGE(x, 1, gw) {
            input(grid[y][x]);
            dmap[y][x] = INT_MAX;
            if (grid[y][x] > grid[ey][ex]) {
                ey = y, ex = x;
            }
        }
    }

    priority_queue<pair<int, pii>> pq;
    pq.push({0, {sy, sx}});
    dmap[sy][sx] = 0;

    while (pq.size()) {
        int cur = -pq.top().fi;
        auto [y, x] = pq.top().se;
        pq.pop();

        if (cur > dmap[y][x]) continue;

        for (const auto& [dy, dx] : DIRS) {
            int ny = y + dy;
            int nx = x + dx;

            if (ny <= 0 || ny > gh || nx <= 0 || nx > gw) continue;

            int delta = grid[ny][nx] - grid[y][x];
            if (abs(delta) > h_lim) continue;

            int nxt = cur;
            if (!delta) nxt++;
            else nxt += delta * (delta > 0 ? c_asc : -c_dsc);

            if (dmap[ny][nx] > nxt) {
                dmap[ny][nx] = nxt;
                pq.push({-nxt, {ny, nx}});
            }
        }
    }

    print(dmap[ey][ex] == INT_MAX ? -1 : dmap[ey][ex]);
}