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

int n, arr[1000];
char dp[1000 * 50 + 1][51];

bool f(int x, int k) {
    if (!x) {
        return 1;
    }

    if (!k) {
        return 0;
    }

    char& res = dp[x][k];
    if (res) {
        return res == 1;
    }

    for (int i = 0; i < n && arr[i] <= x; i++) {
        if (f(x - arr[i], k - 1)) {
            res = 1;
            return 1;
        }
    }

    res = -1;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    FOR(i, input(n)) {
        input(arr[i]);
    }
    int k = input();

    int i = 1;
    for (; f(i, k); i++);

    print(i % 2 ? "jjaksoon" : "holsoon", "win at", i);
}