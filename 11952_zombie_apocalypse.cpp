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

int n_cities;
vector<int> roads[100'001];

bool is_zombie_zone[100'001];
bool is_danger_zone[100'001];

ll dmap[100'001];

void mark_danger_zones(const vector<int>& zombie_cities, int danger_range) {
    queue<int> q;

    for (int zc : zombie_cities) {
        q.push(zc);
        is_danger_zone[zc] = 1;
    }

    for (int q_size; (q_size = q.size()) && danger_range; danger_range--) {
        REP(q_size) {
            int x = q.front();
            q.pop();

            for (int nxt : roads[x]) {
                if (!is_danger_zone[nxt]) {
                    is_danger_zone[nxt] = 1;
                    q.push(nxt);
                }
            }
        }
    }
}

ll dijkstra(int safe_price, int danger_price) {
    fill(&dmap[2], &dmap[1 + n_cities], INT64_MAX);

    priority_queue<pair<ll, int>> pq;
    pq.push({0, 1});

    while (pq.size()) {
        int cur_node = pq.top().se;
        ll cur_cost = -pq.top().fi;
        pq.pop();

        if (dmap[cur_node] < cur_cost) {
            continue;
        }

        for (int nxt : roads[cur_node]) {
            if (is_zombie_zone[nxt]) {
                continue;
            }

            ll nxt_cost = cur_cost + 
                (nxt == n_cities ? 0
                    : (is_danger_zone[nxt] ? danger_price : safe_price));

            if (dmap[nxt] > nxt_cost) {
                dmap[nxt] = nxt_cost;
                pq.push({-nxt_cost, nxt});
            }
        }
    }

    return dmap[n_cities];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    n_cities = input();
    auto [n_roads, n_zombie_cities, danger_range] = inputs<int, 3>();
    auto [safe_price, danger_price] = inputs<int, 2>();

    vector<int> zombie_cities(n_zombie_cities);
    for (int& zc : zombie_cities) {
        is_zombie_zone[input(zc)] = 1;
    }

    REP(n_roads) {
        auto [a, b] = inputs<int, 2>();
        roads[a].push_back(b);
        roads[b].push_back(a);
    }

    mark_danger_zones(zombie_cities, danger_range);

    print(dijkstra(safe_price, danger_price));
}