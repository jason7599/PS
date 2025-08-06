#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0, __n = n; i < __n; i++)
#define RANGE(i, s, e) for(int i = s, __e = e; i <= __e; i++)
#define REP(n) FOR(__, n)
#define LF {cout << '\n';}
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
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF }
template<typename T> bool upmax(T& v, const T& other) { if (v >= other) return 0; v = other; return 1; }
template<typename T> bool upmin(T& v, const T& other) { if (v <= other) return 0; v = other; return 1; }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n_nodes;
int weights[10'001];
vector<int> edges[10'001];

int dp[10'001][2]; // [n][b]. b = whether the prev node was selected.
bool bt[10'001]; // whether we should select this node

int f(int node, int prev, bool prev_b) {
    int& res = dp[node][prev_b];
    if (res != -1) {
        return res;
    }

    int sel = 0, non_sel = 0;
    res = 0;
    for (int nxt : edges[node]) {
        if (nxt == prev) {
            continue;
        }
        upmax(non_sel, f(nxt, node, 0));
        if (!prev_b) {
            upmax(sel, f(nxt, node, 1));
        }
    }

    sel += weights[node];
    if (prev_b || sel < non_sel) {
        res = non_sel;
    } else {
        res = sel;
        bt[node] = 1;
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    n_nodes = input();
    RANGE(i, 1, n_nodes) {
        input(weights[i]);
        dp[i][0] = dp[i][1] = -1;
    }

    REP(n_nodes - 1) {
        auto [a, b] = inputs<int, int>();
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    print(f(6, 0, 0));
}