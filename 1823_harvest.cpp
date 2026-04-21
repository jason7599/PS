#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int len, arr[2000];
int dp[2000][2000];

int f(int l, int r) {
    int v = l + r + 1;

    if (l == len - 1 - r) {
        return arr[l] * v;
    }

    int& res = dp[l][r];
    if (res) {
        return res;
    }

    res = max(
        arr[l] * v + f(l + 1, r),
        arr[len - 1 - r] * v + f(l, r + 1)
    );

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> len;
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    cout << f(0, 0) << '\n';
}