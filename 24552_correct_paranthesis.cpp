#include <bits/stdc++.h>
#define PRINT(x) {cout << x << '\n';}
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, s, e) for(int i = s; i <= e; i++)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int f(const string& s) {
    int l_cnt = 0, r_cnt = 0;
    int csum = 0;
    for (char c : s) {
        if (c == '(') {
            l_cnt++;
            csum++;
        } else {
            r_cnt++;
            if (--csum < 0) {
                return r_cnt;
            }
        }

        if (!csum) {
            l_cnt = 0;
        }
    }

    return l_cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string s;
    cin >> s;

    PRINT(f(s))
}