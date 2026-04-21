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

int n;
char arr[100'001];
char seg[400'004];

char sign(int v) {
    if (!v) return 0;
    return v > 0 ? 1 : -1;
}

char build(int i, int l, int r) {
    if (l == r) return seg[i] = arr[l];

    int m = (l + r) / 2;
    return seg[i] = build(i * 2, l, m) * build(i * 2 + 1, m + 1, r);
}

char query(int i, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 1;
    if (ql <= l && r <= qr) return seg[i];

    int m = (l + r) / 2;
    return query(i * 2, l, m, ql, qr)
        * query(i * 2 + 1, m + 1, r, ql, qr);
}

char update(int i, int l, int r, int p, char v) {
    if (p < l || r < p) return seg[i];
    if (l == r) return seg[i] = v;

    int m = (l + r) / 2;
    return seg[i] = update(i * 2, l, m, p, v)
        * update(i * 2 + 1, m + 1, r, p, v);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_queries;
    while (cin >> n >> n_queries) {
        RANGE(i, 1, n) {
            arr[i] = sign(input());
        }

        build(1, 1, n);

        REP(n_queries) {
            auto [c, a, b] = inputs<char, int, int>();
            if (c == 'C') {
                update(1, 1, n, a, sign(b));
            } else {
                char x = query(1, 1, n, a, b);
                if (!x) {
                    cout << 0;
                } else {
                    cout << (x == 1 ? '+' : '-');
                }
            }
        }
        LF;
    }
}