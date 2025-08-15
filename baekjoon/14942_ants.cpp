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
int arr[100'001];
vector<pii> edges[100'001]; // <to, dist>

int ans[100'001];

vector<int> f(int node, int dist, int parent) {
    vector<int> res;
    if (arr[node] >= dist) {
        arr[node] -= dist;
        res.push_back(node);
    } else {
        ans[node] = node;
    }

    for (const auto& [nxt, d] : edges[node]) {
        if (nxt == parent) {
            continue;
        }
        vector<int> t = f(nxt, d, node);
        for (int i : t) {
            if (arr[i] >= dist) {
                arr[i] -= dist;
                res.push_back(i);
            } else {
                ans[i] = node;
            }
        }
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    RANGE(i, 1, input(n_nodes)) {
        input(arr[i]);
    }
    REP(n_nodes - 1) {
        auto [a, b, d] = inputs<int, int, int>();
        edges[a].push_back({b, d});
        edges[b].push_back({a, d});
    }

    f(1, 0, 0);

    RANGE(i, 1, n_nodes) {
        print(max(ans[i], 1));
    }
}