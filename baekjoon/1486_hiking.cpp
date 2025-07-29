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
template<typename... Args> void input(Args&... args) { ((cin >> args), ...); }
template<typename It> void input(It s, It e) { for (; s != e; ++s) cin >> *s; }
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF}
template<typename It> void print(It s, It e, char sep = ' ') { cout << *s++; while (s != e) cout << sep << *s++; LF}
template<typename T> void upmax(T& v, const T& other) { v = max(v, other); }
template<typename T> void upmin(T& v, const T& other) { v = min(v, other); }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int tlimit, hlimit;
int g_h, g_w, grid[25][25];
int dmap[25][25][2]; // [0] = to hotel, [1] = from hotel

int ans;

void dijkstra(bool b) {
    priority_queue<pair<int, pii>> pq;
    pq.push({0, {0, 0}});
    dmap[0][0][b] = 0;

    while (pq.size()) {
        int c_cost = -pq.top().fi;
        const auto [y, x] = pq.top().se;
        pq.pop();

        if (dmap[y][x][b] < c_cost) {
            continue;
        }

        if (b) {
            if (dmap[y][x][0] != INT_MAX && c_cost + dmap[y][x][0] <= tlimit) {
                upmax(ans, grid[y][x]);
            }
        }

        for (const auto& [dy, dx] : DIRS) {
            int ny = y + dy;
            int nx = x + dx;

            if (ny < 0 || ny >= g_h || nx < 0 || nx >= g_w
            || abs(grid[ny][nx] - grid[y][x]) > hlimit) {
                continue;
            }

            int nx_cost = c_cost;
            if ((!b && grid[y][x] <= grid[ny][nx]) || (b && grid[y][x] >= grid[ny][nx])) {
                nx_cost++;
            } else {
                nx_cost += pow(grid[ny][nx] - grid[y][x], 2);
            }

            if (!b || nx_cost <= tlimit) {
                if (dmap[ny][nx][b] > nx_cost) {
                    dmap[ny][nx][b] = nx_cost;
                    pq.push({-nx_cost, {ny, nx}});
                }
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(g_h, g_w, hlimit, tlimit);
    FOR(y, g_h) {
        FOR(x, g_w) {
            char c;
            input(c);
            grid[y][x] = c >= 'a' ? 26 + c - 'a' : c - 'A';
            FOR(i, 2) dmap[y][x][i] = INT_MAX;
        }
    }
    
    dijkstra(0);
    dijkstra(1);
    
    print(ans);
}