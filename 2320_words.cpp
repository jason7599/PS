#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int vtoi(char c) {
    switch (c) {
        case 'A': return 0;
        case 'E': return 1;
        case 'I': return 2;
        case 'O': return 3;
        case 'U': return 4; 
    }
    return 18934091;
}

struct Word {
    int idx;
    int len;
    int end;
};

int n_words;
vector<Word> words[5];
int dp[1 << 16][5];

int solve(int mask, int start) {
    int& res = dp[mask][start];
    if (res != -1) {
        return res;
    }
    res = 0;
    for (const Word& word : words[start]) {
        if (!(mask & (1 << word.idx))) {
            res = max(res, word.len + solve(mask | (1 << word.idx), word.end));
        }
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n_words;
    for (int i = 0; i < n_words; i++) {
        string s;
        cin >> s;
        words[vtoi(s.front())].push_back(Word{i, (int)s.length(), vtoi(s.back())});
    }

    fill(&dp[0][0], &dp[1 << n_words][0], -1);

    int ans = 0;
    for (int i = 0; i < 5; i++) {
        ans = max(ans, solve(0, i));
    }
    cout << ans << '\n';
}
