#include <bits/stdc++.h>

using namespace std;

struct Seq {
    char c;
    int cnt;
};

vector<Seq> parse(const string& str) {
    vector<Seq> res;

    for (size_t base = 0; base < str.length(); ) {
        size_t t = str.find_first_not_of(str[base], base + 1);
        if (t == -1) {
            t = str.length();
        }
        res.push_back(Seq{str[base], (int)(t - base)});
        base = t;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n_choices;
    string str;
    cin >> n_choices >> str;

    vector<Seq> seqs = parse(str);

    unordered_map<char, int> freqs;
    int nz_freq_cnt = 0;
    int max_seq_len = 0;
    int l = 0;
    int len = 0;
    for (int r = 0; r < seqs.size(); r++) {
        const auto& [c, cnt] = seqs[r];

        if (!freqs[c]++) {
            nz_freq_cnt++;
        }
        len += cnt;
        
        while (nz_freq_cnt > n_choices) {
            if (!--freqs[seqs[l].c]) {
                nz_freq_cnt--;
            }
            len -= seqs[l++].cnt;
        }

        max_seq_len = max(max_seq_len, len);
    }

    cout << max_seq_len << '\n';
}