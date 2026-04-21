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

int ctoi(char c) {
    if (c >= 'a') {
        return 26 + c - 'a';
    }
    return c - 'A';
}

int cap[52][52];
int flow[52][52];
int parent[52];

int get_residual(int u, int v) {
    return cap[u][v] - flow[u][v];
}

int edmonds_karp(int src, int dst) {
    auto bfs = [&]() {
        memset(parent, -1, sizeof parent);
        parent[src] = src;

        queue<int> q({src});
        while (q.size()) {
            int cur = q.front();
            q.pop();

            FOR(nxt, 52) {
                if (parent[nxt] == -1) {
                    if (get_residual(cur, nxt) > 0) {
                        parent[nxt] = cur;
                        if (nxt == dst) {
                            return true;
                        }
                        q.push(nxt);
                    }
                }
            }
        }
        return false;
    };

    int max_flow = 0;

    while (bfs()) {
        int path_flow = INT_MAX;
        for (int n = dst; n != src; n = parent[n]) {
            upmin(path_flow, get_residual(parent[n], n));
        }

        for (int n = dst; n != src; n = parent[n]) {
            flow[parent[n]][n] += path_flow;
            flow[n][parent[n]] -= path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    REP(input()) {
        auto [a, b, c] = inputs<char, char, int>();
        a = ctoi(a), b = ctoi(b);
        cap[a][b] += c;
        cap[b][a] += c;
    }

    print(edmonds_karp(ctoi('A'), ctoi('Z')));
}