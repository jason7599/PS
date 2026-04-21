#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int len;
int src[1005], dst[1005];
int dp[1000][10][10];

int turn(int v, int d) {
    v += d;
    if (v > 9) {
        v -= 10;
    } else if (v < 0) {
        v += 10;
    }
    return v;
}

int f(int idx, int cur, int nxt) {
    if (idx == len) {
        return 0;
    }

    int& res = dp[idx][cur][nxt];
    if (res != -1) {
        return res;
    }

    res = INT_MAX;

    int cur_delta = dst[idx] - cur;

    if (idx + 1 == len) {
        return (bool)cur_delta;
    }

    



    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> len;
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < len; i++) {
            char c;
            cin >> c;
            (j ? dst : src)[i] = c - '0';
        }
    }

    memset(dp, -1, sizeof dp);


}