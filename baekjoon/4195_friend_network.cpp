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

int edges[100'000][2];
int roots[200'000];
int sizes[200'000];

int find_root(int i) {
    if (roots[i] != i) {
        roots[i] = find_root(roots[i]);
    }
    return roots[i];
}

void make_union(int a, int b) {
    a = find_root(a);
    b = find_root(b);

    if (a == b) {
        return;
    }

    roots[max(a, b)] = min(a, b);
    sizes[max(a, b)] += sizes[min(a, b)];
    sizes[min(a, b)] = sizes[max(a, b)];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    REP(input()) {
        int n_edges = input();

        int n_nodes = 0;
        unordered_map<string, int> ids;

        FOR(i, n_edges) {
            FOR(j, 2) {
                auto s = input<string>();
                if (ids.count(s) == 0) {
                    ids[s] = n_nodes++;
                }
                edges[i][j] = ids[s];
            }
        }

        FOR(i, n_nodes) {
            roots[i] = i;
            sizes[i] = 1;
        }

        FOR(i, n_edges) {
            auto [a, b] = edges[i];
            make_union(a, b);
            print(sizes[find_root(a)]);
        }
    }
}