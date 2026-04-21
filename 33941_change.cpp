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
template<typename T> T upmax(T& v, const T& other) { v = max(v, other); return v; }
template<typename T> T upmin(T& v, const T& other) { v = min(v, other); return v; }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n;
int arr[100'000];
int dp[100'000][50];

int f(int i, int mod) {
    if (i == n) {
        return mod ? -1 : 0;
    }

    int& res = dp[i][mod];
    if (res != -2) {
        return res;
    }

    res = -1;
    if (f(i + 1, mod) != -1) {
        res = f(i + 1, mod);
    }
    if (arr[i] > 50 && arr[i] < 2000) {
        if (f(i + 1, (mod + arr[i]) % 50) != -1) {
            upmax(res, arr[i] - 50 + f(i + 1, (mod + arr[i]) % 50));
        }
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    FOR(i, input(n)) {
        arr[i] = input() / 10;
        fill(&dp[i][0], &dp[i][50], -2);
    }

    print(f(0, 0) * 10);
}