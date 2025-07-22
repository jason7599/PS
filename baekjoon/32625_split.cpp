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

int n, arr[100'000];

bool check(int l) {
    int s = -1;
    for (int i = 0; i < n;) {
        int min_v = arr[i];
        int max_v = arr[i++];
        for (int t = l - 1; t; t--, i++) {
            min_v = min(min_v, arr[i]);
            max_v = max(max_v, arr[i]);
        }
        if (s == -1) {
            s = min_v + max_v;
        } else if (s != min_v + max_v) {
            return 0;
        }
    }

    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    input(n);
    FOR(i, n) {
        input(arr[i]);
    }

    for (int l = n / 2; l > 0; l--) {
        if (n % l == 0) {
            if (check(l)) {
                print(1);
                return 0;
            }
        }
    }
    print(0);
}