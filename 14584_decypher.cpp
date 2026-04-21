#include <bits/stdc++.h>
using namespace std;

void shift(string& code) {
    for (char& c : code) {
        if (c++ == 'z') {
            c = 'a';
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string code;
    cin >> code;

    int n_words;
    cin >> n_words;
    vector<string> words(n_words);
    for (string& w : words) {
        cin >> w;
    }

    for (int d = 0; d < 26; d++) {
        shift(code);
        for (const string& w : words) {
            if (code.find(w) != -1) {
                goto brk;
            }
        }
    }
brk:
    cout << code << '\n';
}
