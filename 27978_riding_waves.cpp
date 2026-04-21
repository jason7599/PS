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
bool obsts[500][500];
int dmap[500][500];

int bfs01(pii src, pii dst) {
    deque<pii> dq({src});

    while (dq.size()) {
        auto [y, x] = dq.front();
        dq.pop_front();

        int cur_d = dmap[y][x];

        for (int ny = max(y - 1, 0); ny <= min(y + 1, gh - 1); ny++) {
            for (int nx = max(x - 1, 0); nx <= min(x + 1, gw - 1); nx++) {
                if (obsts[ny][nx]) continue;

                int w = (x >= nx);
                if (cur_d + w < dmap[ny][nx]) {
                    dmap[ny][nx] = cur_d + w;
                    if (w == 0) dq.push_front({ny, nx});
                    else dq.push_back({ny, nx});
                }
            }
        }
    }

    int ans = dmap[dst.fi][dst.se];
    return ans == INT_MAX ? -1 : ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(gh, gw);
    pii src, dst;

    FOR(y, gh) {
        FOR(x, gw) {
            dmap[y][x] = INT_MAX;
            switch (input<char>()) {
            case '#':
                obsts[y][x] = 1;
                break;
            case 'K':
                dmap[y][x] = 0;
                src = {y, x};
                break;
            case '*':
                dst = {y, x};
                break;
            }
        }
    }

    print(bfs01(src, dst));
}