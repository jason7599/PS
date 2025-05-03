#include <bits/stdc++.h>
using namespace std;

string solve(const string& s) {
    int t = 0;
    for (;; t++) {
        bool b = 1;
        for (int i = 0; i < s.length() - t; i++) {
            if (s[t + i] != s[s.length() - 1 - i]) {
                b = 0;
                break;
            }
        }
        if (b) {
            break;
        }
    }
    string res = s;
    for (t--; t >= 0; t--) {
        res.push_back(s[t]);
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n_tc;
    cin >> n_tc;
    while (n_tc--) {
        string s;
        cin >> s;
        cout << solve(s) << '\n';
    }
}