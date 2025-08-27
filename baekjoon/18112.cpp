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

bool vis[1 << 10][11][1 << 10][11];

int f(int sb, int sl, int eb, int el) {
    if (sb == eb && sl == el) {
        return 0;
    }

    queue<pair<pii, pii>> q({{{sb, sl}, {eb, el}}});
    vis[sb][sl][eb][el] = 1;

    auto push = [&](int b, int l) {
        if (l > el || vis[b][l]) {
            return 0;
        }
        if (b == eb & l == el) {
            return 1;
        }
        vis[b][l] = 1;
        q.push({b, l});
    };

    for (int res = 1, q_size; (q_size = q.size()); res++) {
        while (q_size--) {
            const auto [cb, cl] = q.front();
            q.pop();

            FOR(bt, cl - 1) {
                if (push(cb | (1 << bt), cl)) {
                    return res;
                }
            }

            if (cb == (1 << cl) - 1) {
                if (push((1 << cl), cl + 1)) {
                    return res;
                }
            } else {
                if (push(cb + 1, cl)) {
                    return res;
                }
            }

            if (cb) {
                
            }
        }
    }

    return -1;
}

int b2i(string& s) {
    int res = 0;
    for (char c : s) {
        res <<= 1;
        res += c == '1';
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    auto [s, e] = inputs<string, string>();
    print(f(b2i(s), s.length(), b2i(e), e.length()));
}