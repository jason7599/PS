#include <bits/stdc++.h>
#define PRINT(x) {cout << x << '\n';}
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, s, e) for(int i = s; i <= e; i++)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

string str;
ll dp[100][3][3][2];

inline bool is_vowel(char c) {
    return c == 'A'
        || c == 'E'
        || c == 'I'
        || c == 'O'
        || c == 'U';
}

ll f(int i, int vc, int cc, bool lc) {
    if (i == str.length()) {
        return lc;
    }

    ll& res = dp[i][vc][cc][lc];
    if (res != -1) {
        return res;
    }

    if (str[i] != '_') {
        if (is_vowel(str[i])) {
            if (++vc == 3) {
                return res = 0;
            }
            cc = 0;
        } else {
            if (++cc == 3) {
                return res = 0;
            }
            if (str[i] == 'L') {
                lc = 1;
            }
            vc = 0;
        }

        return res = f(i + 1, vc, cc, lc);
    }

    res = 0;
    if (vc != 2) {
        res = 5 * f(i + 1, vc + 1, 0, lc);
    }

    if (cc != 2) {
        res += 20 * f(i + 1, 0, cc + 1, lc)
            + f(i + 1, 0, cc + 1, 1);
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> str;
    fill(&dp[0][0][0][0], &dp[str.length()][0][0][0], -1);

    PRINT(f(0, 0, 0, 0))
}