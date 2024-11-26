#include <iostream>
#include <algorithm>

#define INF 987654321

using namespace std;

int n, a[1000][3], dp[1000][3];

int func(int houseIndex, int colorIndex) {

    if (dp[houseIndex][colorIndex]) return dp[houseIndex][colorIndex];
    if (houseIndex == n - 1) {
        dp[houseIndex][colorIndex] = a[houseIndex][colorIndex];
        return dp[houseIndex][colorIndex];
    }

    int res = INF;
    for (int color = 0; color < 3; color++) {
        if (color != colorIndex)
            res = min(res, func(houseIndex + 1, color));
    }

    return dp[houseIndex][colorIndex] = res + a[houseIndex][colorIndex];

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];

    cout << min(func(0, 0), min(func(0, 1), func(0, 2)));


}