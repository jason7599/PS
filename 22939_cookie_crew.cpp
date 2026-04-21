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
template<typename T> T input(T& t) { cin >> t; return t; }
template<typename... Args> void input(Args&... args) { ((cin >> args), ...); }
template<typename... Args> tuple<Args...> inputs() { tuple<Args...> t; apply([](auto&... args){input(args...);}, t); return t; }
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF; }
template<typename T> T upmax(T& v, const T& other) { v = max(v, other); return v; }
template<typename T> T upmin(T& v, const T& other) { v = min(v, other); return v; }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int g_sz;

int c2i(char c) {
    switch (c) {
    case 'J': return 0;
    case 'C': return 1;
    case 'B': return 2;
    case 'W': return 3;
    default: assert(0); return -1;
    }
}

vector<pii> pos[4];

const string ROLES[4] = {"Assassin", "Healer", "Mage", "Tanker"};

int l1_dist(pii& lhs, pii& rhs) {
    return abs(lhs.fi - rhs.fi) + abs(lhs.se - rhs.se);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    input(g_sz);
    pii src, dst;

    FOR(y, g_sz) {
        FOR(x, g_sz) {
            auto c = input<char>();
            switch (c) {
            case 'H':
                src = {y, x};
                break;
            case '#':
                dst = {y, x};
                break;
            case 'X':
                break;
            default:
                pos[c2i(c)].push_back({y, x});
            }
        }
    }

    int min_dist = INT_MAX;
    int ans;
    FOR(i, 4) {
        vector<int> seq = {0, 1, 2};
        do {
            int dist = 0;
            FOR(p, 4) {
                pii prev = p ? pos[i][seq[p - 1]] : src;
                pii cur = p < 3 ? pos[i][seq[p]] : dst;
                dist += l1_dist(prev, cur);
                if (dist >= min_dist) {
                    break;
                }
            }
            if (dist < min_dist) {
                min_dist = dist;
                ans = i;
            }
        } while (next_permutation(seq.begin(), seq.end()));
    }

    print(ROLES[ans]);
}