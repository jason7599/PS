#include <bits/stdc++.h>

using namespace std;

int reqs[52];
int nz_reqs;

int& get_req(char c) {
    return reqs[c - (c >= 'a' ? 'a' : 'A' - 26)];
}

void chreq(char c, int d) {
    int& v = get_req(c);
    if (!v) {
        nz_reqs++;
    }
    v += d;
    if (!v) {
        nz_reqs--;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int word_len, text_len;
    cin >> word_len >> text_len;

    string word, text;
    cin >> word >> text;

    for (char c : word) {
        chreq(c, 1);
    }
    for (int i = 0; i < word_len; i++) {
        chreq(text[i], -1);
    }

    int ans = !nz_reqs;
    for (int i = word_len; i < text_len; i++) {
        chreq(text[i], -1);
        chreq(text[i - word_len], 1);
        ans += !nz_reqs;
    }

    cout << ans << '\n';
}