#include <bits/stdc++.h>
#define PRINT(x) {cout << x << '\n';}
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, s, e) for(int i = s; i <= e; i++)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int g_h, g_w;
int csum[1001][1001];
int dp[1001][1001];

int get_sum(int y, int x0, int x1) {
    return csum[y][x1] - csum[y][x0 - 1];
}

int f(int y, int x) {
    if (y == g_h) {
        return get_sum(g_h, x, g_w);
    }

    int& res = dp[y][x];
    if (res != INT_MIN) {
        return res;
    }

    FORR(nx, 1, g_w) {
        res = max(res,
            get_sum(y, min(x, nx), max(x, nx)) + f(y + 1, nx));
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> g_h >> g_w;
    FORR(y, 1, g_h) {
        FORR(x, 1, g_w) {
            cin >> csum[y][x];
            csum[y][x] += csum[y][x - 1];
            dp[y][x] = INT_MIN;
        }
    }

    PRINT(f(1, 1))
}