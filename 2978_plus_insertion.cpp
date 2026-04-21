#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

pii dp[1000][5001]; // dp[i][v]: 만들어야 하는 값이 v이고, 현재 idx = i일때 <최소 더하기 개수, 길이>

pii f(const string& s, int v, int i) {
    if (i == s.length()) {
        return {v ? INT_MAX : 0, 0};
    }

    if (!v) {
        if (s.find_first_not_of('0', i) == -1) {
            return {0, s.length() - i};
        }
        return {INT_MAX, 0};
    }

    pii& res = dp[i][v];
    if (res.first != -1) {
        return res;
    }

    res.first = INT_MAX;
    for (int sv = s[i] - '0', l = 1; i + l <= s.length() && sv <= v; sv = sv * 10 + (s[i + l++] - '0')) {
        pii t = f(s, v - sv, i + l);
        if (t.first < res.first) {
            res = {1 + t.first, l};
        }
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string raw;
    cin >> raw;

    size_t t = raw.find('=');
    string s = raw.substr(0, t);
    int v = stoi(raw.substr(t + 1));

    fill(&dp[0][0], &dp[s.length() - 1][v + 1], make_pair(-1, 0));

    for (int i = 0, sv = v; i < s.length();) {
        int l = f(s, sv, i).second;
        string ss = s.substr(i, l);
        cout << ss;

        sv -= stoi(ss);
        i += l;

        if (i < s.length()) {
            cout << '+';
        }
    }
    cout << '=' << v << '\n';
}