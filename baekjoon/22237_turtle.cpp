#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0, _n = n; i < _n; i++)
#define RANGE(i, s, e) for(int i = s, _e = e; i <= _e; i++)
#define REP(n) FOR(i, n)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
template<typename T> T input() { T t; cin >> t; return t; } int input() { return input<int>(); }
template<typename T> void input(T& t) { cin >> t; }
template<typename T, typename... Args> void input(T& t, Args&... args) { cin >> t; input(args...); }
template<typename T> void print(const T& t) { cout << t << '\n'; }
template<typename T, typename... Args> void print(const T& t, const Args&... args) { cout << t << ' '; print(args...); }

const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const string DIRSTR = "DRUL";

int g_h, g_w;
bool home_zone[1000][1000];
bool obst_zone[1000][1000];
int path[1000][1000];

pii start, home;
vector<pii> turtle;
int turtle_max_y, turtle_min_x, turtle_max_x;

pii endp{-1, -1};

bool is_oob(int y, int x) {
    return y < 0 || y >= g_h || x < 0 || x >= g_w;
}

void map_zones(pii pos, bool zone[][1000]) {
    for (const auto& [y, x] : turtle) {
        int ny = pos.first - y;
        int nx = pos.second - x;

        if (!is_oob(ny, nx)) {
            zone[ny][nx] = 1;
        }
    }
}

void bfs() {
    queue<pii> q({start});
    path[start.first][start.second] = 0;

    for (; q.size(); q.pop()) {
        const auto [y, x] = q.front();

        if (home_zone[y][x]) {
            endp = {y, x};
            return;
        }

        FOR(d, 4) {
            int ny = y + DIRS[d].first;
            int nx = x + DIRS[d].second;

            if (is_oob(ny, nx + turtle_min_x) || is_oob(ny + turtle_max_y, nx + turtle_max_x)) {
                continue;
            }

            if (obst_zone[ny][nx]) {
                continue;
            }

            if (path[ny][nx] == -1) {
                path[ny][nx] = d;
                q.push({ny, nx});
            }
        }
    }
}

void print_path(int y, int x) {
    if (y == start.first && x == start.second) {
        return;
    }

    int d = path[y][x];

    print_path(y - DIRS[d].first, x - DIRS[d].second);

    cout << DIRSTR[d];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    vector<pii> obsts;
    
    input(g_h, g_w);
    FOR(y, g_h) {
        FOR(x, g_w) {
            path[y][x] = -1;
            switch (input<char>()) {
            case '#':
                obsts.push_back({y, x});
                break;
            case 'H':
                home = {y, x};
                break;
            case 'T':
                turtle.push_back({y, x});
            }
        }
    }

    start = turtle.front();
    for (auto& [y, x] : turtle) {
        y -= start.first;
        x -= start.second;

        turtle_max_y = y;
        turtle_min_x = min(turtle_min_x, x);
        turtle_max_x = max(turtle_max_x, x);
    }

    map_zones(home, home_zone);
    for (const pii& obst : obsts) {
        map_zones(obst, obst_zone);
    }
    
    bfs();

    if (endp.first != -1) {
        print_path(endp.first, endp.second);
        cout << '\n';
    } else {
        print(-1);
    }
}