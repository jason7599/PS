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
template<typename T> T upmax(T& v, const T& other) { v = max(v, other); return v; }
template<typename T> T upmin(T& v, const T& other) { v = min(v, other); return v; }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n_nodes;
int weights[10'001];
vector<int> edges[10'001];

int dp[10'001][2];

int f(int node, int prev, bool select) {
    int& res = dp[node][select];
    if (res != -1) {
        return res;
    }

    res = 0;
    for (int nxt : edges[node]) {
        if (nxt == prev) {
            continue;
        }
        
        int t = f(nxt, node, 0); // don't select next
        if (!select) { // select next, only possible if cur node is not to be selected
            upmax(t, f(nxt, node, 1));
        }

        res += t;
    }

    if (select) {
        res += weights[node];
    }

    return res;
}

void bt(int node, int prev, bool prev_select, vector<int>& res) {
    if (!prev_select) {
        if (dp[node][0] < dp[node][1]) {
            res.push_back(node);
            prev_select = 1;
        }
    } else {
        prev_select = 0;
    }

    for (int nxt : edges[node]) {
        if (nxt == prev) {
            continue;
        }
        bt(nxt, node, prev_select, res);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    RANGE(i, 1, input(n_nodes)) {
        input(weights[i]);
        dp[i][0] = dp[i][1] = -1;
    }

    REP(n_nodes - 1) {
        auto [a, b] = inputs<int, int>();
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    print(max(f(1, 0, 0), f(1, 0, 1)));

    vector<int> res;
    bt(1, 0, 0, res);
    sort(res.begin(), res.end());

    for (int i : res) {
        cout << i << ' ';
    } LF
}