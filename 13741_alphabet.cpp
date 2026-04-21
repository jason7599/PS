#include <bits/stdc++.h>
using namespace std;

string str;
vector<int> dp;

int solve(int idx) {
    char c = str[idx];
    if (c == 'z') {
        return 0;
    }

    int& res = dp[idx];
    if (res != -1) {
        return res;
    }

    res = 'z' - c;
    for (int nidx = idx + 1; nidx < str.length(); nidx++) {
        if (str[nidx] > c) {
            res = min(res, str[nidx] - c - 1 + solve(nidx));
        }
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> str;
    dp.resize(str.length(), -1);
    
    int ans = INT_MAX;
    for (int i = 0; i < str.length(); i++) {
        ans = min(ans, str[i] - 'a' + solve(i));
    }
    cout << ans << '\n';
}
