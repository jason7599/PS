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

int g_h, g_w;
int tot;
bool grid[1001][1001];

bool stop(int y, int x) {
    return y <= 0 || y > g_h || x <= 0 || x > g_w || grid[y][x]; 
}

void go(int y, int x, int dy, int dx) {
    for (; !stop(y, x); y += dy, x += dx) {
        grid[y][x] = true;
        tot--;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(g_h, g_w);
    tot = g_h * g_w;

    REP(input()) {
        switch (input()) {
            case 1: {
                auto [dy, dx, y, x] = inputs<int, 4>();
                go(y, x, dy, dx);
                break;
            }
            case 2: {
                auto [y, x] = inputs<int, 2>();
                print(grid[y][x]);
                break;
            }
            case 3: {
                print(tot);
            }
        }
    }
}