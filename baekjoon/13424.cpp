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

int dmap[101][101];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    REP(input()) {
        int n_nodes = input();
        RANGE(i, 1, n_nodes) {
            RANGE(j, 1, n_nodes) {
                dmap[i][j] = i == j ? 0 : 1e9;
            }
        }

        REP(input()) {
            auto [a, b, d] = inputs<int, 3>();
            dmap[a][b] = dmap[b][a] = d;
        }

        RANGE(k, 1, n_nodes) {
            RANGE(i, 1, n_nodes) {
                RANGE(j, 1, n_nodes) {
                    upmin(dmap[i][j], dmap[i][k] + dmap[k][j]);
                }
            }
        }

        vector<int> targs(input());
        for (int &t : targs) input(t);

        int min_d = INT_MAX;
        int min_d_node = -1;
        RANGE(i, 1, n_nodes) {
            int d = 0;
            for (int t : targs) {
                d += dmap[i][t];
                if (d > min_d) {
                    break;
                }
            }
            if (d < min_d) {
                min_d = d;
                min_d_node = i;
            }
        }

        print(min_d_node);
    }
}