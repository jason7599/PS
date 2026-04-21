#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    int ans = 0;
    int cur = 0;
    while (n--) {
        int x;
        cin >> x;
        if (x) {
            ans += ++cur;
        } else {
            cur = 0;
        }
    }

    cout << ans << '\n';
}