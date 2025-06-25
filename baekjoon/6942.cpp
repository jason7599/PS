#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

char f(char c) {
    switch (c) {
        case '0':
        case '1':
        case '8':
            return c;
        case '6':
            return '9';
        case '9':
            return '6';
    }
    return -1;
}

bool chk(const string& s) {
    if (s.length() % 2) {
        char m = s[s.length() / 2];
        if (f(m) != m) {
            return 0;
        }
    }
    for (int i = 0; i < s.length() / 2; i++) {
        if (f(s[i]) != s[s.length() - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int s, e;
    cin >> s >> e;

    int cnt = 0;
    for (int i = s; i <= e; i++) {
        cnt += chk(to_string(i));
    }
    cout << cnt << '\n';
}
