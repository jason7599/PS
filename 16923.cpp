#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s;
    cin >> s;

    unordered_set<char> v(s.begin(), s.end());

    if (v.size() < 26) {
        char c;
        for (c = 'a'; v.count(c); c++);
        cout << s << c << '\n';
    } else { 
        // every char has appeared 
        int i;
        for (i = s.length() - 1; i > 0 && s[i] < s[i - 1]; i--);
        if (!i) {
            cout << -1 << '\n';
        } else {
            char c = s[i];
            for (int t = i + 1; t < s.length(); t++) {
                if (s[t] > s[i - 1] && s[t] < c) {
                    c = s[t];
                }
            }
            cout << s.substr(0, i - 1) << c << '\n';
        }
    }
}
