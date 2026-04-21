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

int g_sz;
int init_hp, add_hp;
int n_milk;
pii milk_pos[10];
pii src;

int get_dist(int y0, int x0, int y1, int x1) {
    return abs(y0 - y1) + abs(x0 - x1);
}

int get_dist(pii pos0, pii pos1) {
    return get_dist(pos0.fi, pos0.se, pos1.fi, pos1.se);
}

int ans;

void brute(pii pos, int hp, int mask) {
    int score = 0;
    FOR(m, n_milk) {
        if (mask & (1 << m)) {
            score++;
        } else {
            if (get_dist(pos, milk_pos[m]) <= hp) {
                brute(milk_pos[m], hp - get_dist(pos, milk_pos[m]) + add_hp, mask | (1 << m));
            }
        }
    }
    if (get_dist(pos, src) <= hp) {
        upmax(ans, score);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(g_sz, init_hp, add_hp);

    FOR(y, g_sz) {
        FOR(x, g_sz) {
            int t = input();
            if (t == 1) {
               src = {y, x}; 
            } else if (t == 2) {
                milk_pos[n_milk++] = {y, x};
            }
        }
    }

    brute(src, init_hp, 0);

    print(ans);
}