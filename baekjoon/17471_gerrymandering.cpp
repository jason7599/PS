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

struct Area {
    int pop;
    vector<int> adjs;
};

int n_areas;
Area areas[10];

int get_pop(int idx, bool zone_bit, int zone_mask, int& vis_mask) {
    int res = areas[idx].pop;
    vis_mask |= (1 << idx);

    for (int nx : areas[idx].adjs) {
        if ((((zone_mask >> nx) & 1) == zone_bit) && !(vis_mask & (1 << nx))) {
            res += get_pop(nx, zone_bit, zone_mask, vis_mask);
        }
    }

    return res;
}

int get_pop(int idx, bool zone_bit, int zone_mask) {
    int vis_mask = 0;
    return get_pop(idx, zone_bit, zone_mask, vis_mask);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(n_areas);
    int total_pop = 0;
    FOR(i, n_areas) {
        total_pop += input(areas[i].pop);
    }

    FOR(i, n_areas) {
        areas[i].adjs.resize(input());
        for (int& a : areas[i].adjs) {
            a = input() - 1;
        }
    }

    int min_diff = INT_MAX;
    RANGE(zone_mask, 1, (1 << (n_areas - 1)) - 1) {
        int z0 = -1, z1 = -1;
        for (int b = 0; z0 == -1 || z1 == -1; b++) {
            ((zone_mask & (1 << b)) ? z1 : z0) = b;
        }

        assert(min(z0, z1) != -1);

        int t = get_pop(z0, 0, zone_mask);
        if (t + get_pop(z1, 1, zone_mask) == total_pop) {
            upmin(min_diff, abs(t - (total_pop - t)));
        }
    }

    print(min_diff == INT_MAX ? -1 : min_diff);
}