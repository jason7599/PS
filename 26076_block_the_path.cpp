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
bool walls[2000][2000];

bool is_endpoint(int y, int x) {
    return (!y && !x) || (y == gh - 1 && x == gw - 1);
}

bool is_zone0(int y, int x) {
    return !is_endpoint(y, x) && (y == gh - 1 || !x);
}

bool is_zone1(int y, int x) {
    return !is_endpoint(y, x) && (!y || x == gw - 1);
}

int dmap[2000][2000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(gh, gw);
    deque<pii> dq;
    FOR(y, gh) {
        FOR(x, gw) {
            input(walls[y][x]);
            if (is_zone0(y, x)) {
                dq.push_front({y, x});
                dmap[y][x] = !walls[y][x];
            } else {
                dmap[y][x] = INT_MAX;
            }
        }
    }

    int ans = INT_MAX;
    while (dq.size()) {
        auto [y, x] = dq.front();
        dq.pop_front();

        int cur = dmap[y][x];
        if (is_zone1(y, x)) {
            upmin(ans, cur);
        }

        for (int ny = max(y - 1, 0); ny <= min(y + 1, gh - 1); ny++) {
            for (int nx = max(x - 1, 0); nx <= min(x + 1, gw - 1); nx++) {
                if (y == ny && x == nx) continue;
                if (is_endpoint(ny, nx)) continue;

                bool w = !walls[ny][nx];
                if (cur + w < dmap[ny][nx]) {
                    dmap[ny][nx] = cur + w;
                    if (!w) dq.push_front({ny, nx});
                    else dq.push_back({ny, nx}); 
                }
            }
        }
    }

    print(ans);
}