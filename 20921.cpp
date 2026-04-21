#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    for (int l = 1, r = n; l <= r;) {
        if (k >= r - l) {
            k -= r - 1;
            cout << r-- << ' ';
        } else {
            cout << l++ << ' ';
        }
    }
    cout << '\n';
}