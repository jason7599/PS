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
vector<int> edges[200'001];
int dmap[200'001];

void bfs(int start) {
    fill(&dmap[1], &dmap[1 + n_nodes], INT_MAX);
    dmap[start] = 0;
    queue<int> q({start});

    for (int q_size, dist = 1; (q_size = q.size()); dist++) {
        while (q_size--) {
            int cur = q.front();
            q.pop();

            for (int nxt : edges[cur]) {
                if (dmap[nxt] == INT_MAX) {
                    dmap[nxt] = dist;
                    q.push(nxt);
                }
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(n_nodes);
    auto [n_edges, tp_from, tp_to, tp_time] = inputs<int, int, int, int>();

    REP(n_edges) {
        auto [from, to] = inputs<int, int>();
        edges[from].push_back(to);
    }

    bfs(1);

    int og_dist = dmap[n_nodes];
    int tp_dist = dmap[tp_from];

    if (tp_dist == INT_MAX) {
        if (og_dist == INT_MAX) {
            print('x');
        } else {
            print(og_dist);
        }
    } else {
        bfs(tp_to);
        
        if (dmap[n_nodes] == INT_MAX) {
            if (og_dist == INT_MAX) {
                print('x');
            } else {
                print(og_dist);
            }
        } else {
            if (dmap[tp_from] < tp_time) {
                print("-inf");
            } else {
                print(min(og_dist, tp_dist - tp_time + dmap[n_nodes]));
            }
        }
    }

}