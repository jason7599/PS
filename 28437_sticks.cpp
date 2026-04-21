#include <bits/stdc++.h>

using namespace std;

const int MAX_VAL = 100'000;

bool srcs[MAX_VAL + 1];
int dp[MAX_VAL + 1];

int solve(int dst) {

    int& res = dp[dst];
    if (res)
        return max(res, 0);
    
    res = srcs[dst]; // / 1 => dst

    for (int i = 2; i <= sqrt(dst); i++) {
        if (dst % i == 0) {
            res += solve(dst / i);
            if (i != dst / i)
                res += solve(i);
        }
    }
    
    if (dst != 1) // / dst => 1
        res += srcs[1];

    if (!res) {
        res = -1;
        return 0;
    }

    return res;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n_src;
    cin >> n_src;

    while (n_src--) {
        int src;
        cin >> src;
        srcs[src] = 1;
    }

    int n_dst;
    cin >> n_dst;

    while (n_dst--) {
        int dst;
        cin >> dst;
        cout << solve(dst) << ' ';
    }
    cout << '\n';
}