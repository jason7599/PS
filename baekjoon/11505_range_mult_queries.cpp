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

const int MOD = 1e9 + 7;

int n, arr[1'000'000];
int seg[4'000'004];

int build(int idx, int l, int r) {
    if (l == r) {
        return seg[idx] = arr[l];
    }
    int m = (l + r) / 2;
    return seg[idx] = ((ll)build(idx * 2, l, m) * build(idx * 2 + 1, m + 1, r)) % MOD; 
}

int query(int idx, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) {
        return 1;
    }

    if (ql <= l && r <= qr) {
        return seg[idx];
    }

    int m = (l + r) / 2;
    return ((ll)query(2 * idx, l, m, ql, qr) * query(2 * idx + 1, m + 1, r, ql, qr)) % MOD;
}

int update(int idx, int l, int r, int pos, int val) {
    if (pos < l || r < pos) {
        return seg[idx];
    }

    if (l == r) {
        return seg[idx] = val;
    }

    int m = (l + r) / 2;
    return seg[idx] = ((ll)update(2 * idx, l, m, pos, val) * update(2 * idx + 1, m + 1, r, pos, val)) % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(n);
    auto [n_updates, n_queries] = inputs<int, 2>();

    FOR(i, n) {
        input(arr[i]);
    }

    build(1, 0, n - 1);

    REP(n_updates + n_queries) {
        auto [a, b, c] = inputs<int, 3>();
        if (a == 1) {
            update(1, 0, n - 1, b - 1, c);
        } else {
            print(query(1, 0, n - 1, b - 1, c - 1));
        }
    }
}