#include <bits/stdc++.h>
#define COUT(x) {cout << x << '\n';}
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int n_words;
string words[10];
int cnts[8][26];
int conv[26];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n_words;
    unordered_set<char> char_set;
    FOR(i, n_words) {
        string& w = words[i];
        cin >> w;
        FOR(j, w.length()) {
            cnts[w.length() - j - 1][w[j] - 'A']++;
            char_set.insert(w[j]);
        }
    }

    vector<char> chars(char_set.begin(), char_set.end());
    sort(chars.begin(), chars.end(), [&](char lhs, char rhs) {
        int pos = 7;
        for (; pos >= 0 && cnts[pos][lhs - 'A'] == cnts[pos][rhs - 'A']; pos--);
        return pos == -1 || cnts[pos][lhs - 'A'] > cnts[pos][rhs - 'A'];
    });

    FOR(i, chars.size()) {
        conv[chars[i] - 'A'] = 9 - i;
    }

    ll ans = 0;
    for (const string& w : words) {
        ll t = 0;
        for (char c : w) {
            t = t * 10 + conv[c - 'A'];
        }
        ans += t;
    }

    COUT(ans)
}