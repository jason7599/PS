#include <bits/stdc++.h>
using namespace std;

inline void p(int n) {
    cout << string(n, '@') << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        p(n * 5);
    }
    for (int i = 0; i < 4 * n; i++) {
        p(n);
    }
}
