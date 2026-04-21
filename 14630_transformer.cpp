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

int n_states;
string states[1001];
int dmap[1001];

int get_cost(int i, int j) {
    static int dp[1001][1001];
    
    if (i > j) {
        swap(i, j);
    }

    int& res = dp[i][j];
    if (res) {
        return max(res, 0);
    }
    
    FOR(t, states[i].length()) {
        res += pow(states[i][t] - states[j][t], 2);
    }

    if (!res) {
        res = -1;
        return 0;
    }

    return res;
}

int d(int s, int e) {
    dmap[s] = 0;
    priority_queue<pii> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        int c_cost = -pq.top().fi;
        int c_node = pq.top().se;
        pq.pop();

        if (dmap[c_node] < c_cost) {
            continue;
        }

        RANGE(nx, 1, n_states) {
            int nx_cost = c_cost + get_cost(c_node, nx);
            if (dmap[nx] > nx_cost) {
                dmap[nx] = nx_cost;
                pq.push({-nx_cost, nx});
            }
        }
    }

    return dmap[e];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    RANGE(i, 1, input(n_states)) {
        input(states[i]);
        dmap[i] = INT_MAX;
    }

    auto [s, e] = inputs<int, int>();

    print(d(s, e));
}