#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    int cnt = 0;
    for (int t = n; t; t >>= 1) {
        cnt += t % 2;
    }

    int ans = 0;
    for (int b = 0, p = -1; cnt > k; b++) {
        if (!(n & (1 << b))) {
            continue;
        }
        if (p != -1) {
            ans += (1 << b) - (1 << p);
            p = b + 1;
            cnt--;
        } else {
            p = b;
        }
    }

    cout << ans << '\n';
}