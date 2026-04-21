#include <bits/stdc++.h>
#define FOR(i, n) for (ll i = 0, _n = n; i < _n; i++)
#define RANGE(i, s, e) for (ll i = s, _e = e; i <= _e; i++)
#define REP(n) for (ll _ = 0, _n = n; _ < _n; _++)
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
template<typename T> T input(T& t) { cin >> t; return t; }
template<typename... Args> void input(Args&... args) { ((cin >> args), ...); }
template<typename... Args> tuple<Args...> inputs() { tuple<Args...> t; apply([](auto&... args){input(args...);}, t); return t; }
template<typename T, int C> array<T, C> inputs() { array<T, C> arr; for (T& t : arr) cin >> t; return arr; }
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF; }
template<typename T> T upmax(T& v, const T& other) { v = max(v, other); return v; }
template<typename T> T upmin(T& v, const T& other) { v = min(v, other); return v; }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n;
int dmap[51][51];
int res[51];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(n);
    RANGE(i, 1, n) {
        fill(&dmap[i][1], &dmap[i][1 + n], 1e9);
        dmap[i][i] = 0;
    }

    while (1) {
        auto [a, b] = inputs<int, 2>();
        if (a == -1) {
            break;
        }
        dmap[a][b] = dmap[b][a] = 1;
    }

    RANGE(k, 1, n) {
        RANGE(i, 1, n) {
            RANGE(j, 1, n) {
                upmin(dmap[i][j], dmap[i][k] + dmap[k][j]);
            }
        }
    }

    int mn = 1e9;
    int n_mn;

    RANGE(i, 1, n) {
        RANGE(j, 1, n) {
            upmax(res[i], dmap[i][j]);
        }
        if (res[i] < mn) {
            mn = res[i];
            n_mn = 1;
        } else if (res[i] == mn) {
            n_mn++;
        }
    }

    print(mn, n_mn);
    RANGE(i, 1, n) {
        if (res[i] == mn) {
            cout << i << ' ';
        }
    }
    LF;
}