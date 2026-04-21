#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e5;

int w, h;
int dp[100][100];

const int DIRS[2][2] = {{1, 0}, {0, 1}};

bool is_oob(int y, int x) {
    return 0 < y && y 
}

int solve(int x, int y) {
    if (x == w || y == h) {
        return 1;
    }
    int& res = dp[x][y];
    if (res) return res;

    for (int d = 0; d < 2; d++) {
        int ny = y + DIRS[d][0];
        int nx = x + DIRS[d][1];


    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> w >> h;
}