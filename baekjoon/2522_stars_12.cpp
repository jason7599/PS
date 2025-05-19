#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 0; i < 2 * n - 1; i++) {
        int t = i <= n - 1 ? i : 2 * n - 2 - i;
        cout << string(n - 1 - t, ' ');
        cout << string(t + 1, '*') << '\n';
    }
}
