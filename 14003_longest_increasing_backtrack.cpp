#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0, _n = n; i < _n; i++)
#define RANGE(i, s, e) for(int i = s, _e = e; i <= _e; i++)
#define REP(n) FOR(i, n)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
template<typename T> T input() { T t; cin >> t; return t; } int input() { return input<int>(); }
template<typename T> T input(T& t) { cin >> t; return t; }
template<typename T, typename... Args> void input(T& t, Args&... args) { cin >> t; input(args...); }
template<typename T> void print(const T& t) { cout << t << '\n'; }
template<typename T, typename... Args> void print(const T& t, const Args&... args) { cout << t << ' '; print(args...); }

int n, arr[1'000'001];
pii dp[1'000'001];

pii f(int i) {
    pii& res = dp[i];
    if (res.first) {
        return res;
    }

    res.second = i;
    RANGE(t, i + 1, n) {
        if (arr[i] < arr[t]) {
            pii nxt = f(t);
            if (res.first < nxt.first) {
                res = {nxt.first, t};
            }
        }
    }

    res.first++;
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    RANGE(i, 1, input(n)) {
        input(arr[i]);
    }

    print(f(0).first - 1);
    for (int i = 0; i != dp[i].second; i = dp[i].second) {
        cout << arr[dp[i].second] << ' ';
    }
    cout << '\n';
}