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
int grid[700][700];
int dmap[700][700]; // min # of spray needed

bool chk(int thold, int n_use) {
    FOR(y, gh) {
        fill(&dmap[y][0], &dmap[y][gw], INT_MAX);
    }
    dmap[0][0] = 0;
    deque<pii> dq({{0, 0}});

    while (dq.size()) {
        auto [y, x] = dq.front();
        dq.pop_front();

        int cur = dmap[y][x];

        for (const auto& [dy, dx] : DIRS) {
            int ny = y + dy;
            int nx = x + dx;

            if (0 <= ny && ny < gh && 0 <= nx && nx < gw) {
                bool w = grid[ny][nx] > thold;
                if (dmap[ny][nx] > cur + w) {
                    dmap[ny][nx] = cur + w;
                    if (!w) dq.push_front({ny, nx});
                    else dq.push_back({ny, nx});
                }
            }
        }
    }

    return dmap[gh - 1][gw - 1] <= n_use;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(gh, gw);
    int mx_use = input();

    int mx_elem = 0;
    FOR(y, gh) {
        FOR(x, gw) {
            upmax(mx_elem, input(grid[y][x]));
        }
    }

    int ans = -1;
    for (int l = 0, r = mx_elem; l <= r;) {
        int m = (l + r) >> 1;
        if (chk(m, mx_use)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    print(ans);
}