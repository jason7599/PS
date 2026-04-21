#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

vector<string> strs;

bool check(int base) {
    unordered_set<string> set;
    for (const string& str : strs) {
        string t = str.substr(base);
        if (set.count(t)) {
            return 0;
        }
        set.insert(t);
    }
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int len, n_str;
    cin >> len >> n_str;

    strs.resize(n_str, string(len, ' '));

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < n_str; j++) {
            cin >> strs[j][i];
        }
    }

    int ans;
    for (int l = 0, r = len - 1; l <= r;) {
        int m = (l + r) >> 1;
        if (check(m)) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << ans << '\n';
}