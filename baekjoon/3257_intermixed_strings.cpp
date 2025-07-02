#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

string a, b, c;

int ans[300];
bool vis[151][151];

bool f(int ai, int bi) {
    int i = ai + bi;
    if (i == c.length()) {
        return 1;
    }

    if (vis[ai][bi]) {
        return 0;
    }

    vis[ai][bi] = 1;

    if (ai < a.length() && c[i] == a[ai]) {
        if (f(ai + 1, bi)) {
            ans[i] = 1;
            return 1;
        }
    }

    if (bi < b.length() && c[i] == b[bi]) {
        if (f(ai, bi + 1)) {
            ans[i] = 2;
            return 1;
        }
    }

    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> a >> b >> c;

    f(0, 0);

    for (int i = 0; i < c.length(); i++) {
        cout << ans[i];
    }
    cout << '\n';
}