#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int ans = 0;
    for (int i = 0; i < 64; i++) {
        char c;
        cin >> c;
        if ((i / 8 + i) % 2 == 0 && c == 'F') {
            ans++;
        }
    }
    cout << ans << '\n';
}