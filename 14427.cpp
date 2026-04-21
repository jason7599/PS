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
int arr[100'001];
pii seg[400'004]; // <min, min_idx>

pii build(int idx, int l, int r) {
    if (l == r) {
        return seg[idx] = {arr[l], l};
    }

    int m = (l + r) / 2;
    return seg[idx] = min(
        build(idx * 2, l, m),
        build(idx * 2 + 1, m + 1, r)
    );
}

pii query(int idx, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) {
        return {INT_MAX, 0};
    }

    if (ql <= l && r <= qr) {
        return seg[idx];
    }

    int m = (l + r) / 2;
    return min(
        query(idx * 2, l, m, ql, qr),
        query(idx * 2 + 1, m + 1, r, ql, qr)
    );
}

pii update(int idx, int l, int r, int pos, int val) {
    if (pos < l || r < pos) {
        return seg[idx];
    }

    if (l == r) {
        seg[idx].fi = val;
        return seg[idx];
    }

    int m = (l + r) / 2;
    return seg[idx] = min(
        update(idx * 2, l, m, pos, val),
        update(idx * 2 + 1, m + 1, r, pos, val)
    );
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    RANGE(i, 1, input(n)) {
        input(arr[i]);
    }

    build(1, 1, n);

    REP(input()) {
        if (input() == 1) {
            auto [pos, val] = inputs<int, 2>();
            update(1, 1, n, pos, val);
        } else {
            print(query(1, 1, n, 1, n).se);
        }
    }
}