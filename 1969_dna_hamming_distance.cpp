#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n_seqs, seq_len;
    cin >> n_seqs >> seq_len;

    struct Info {
        unordered_map<char, int> freq_map;
        int max_freq = 0;
        char max_freq_char;
    };

    vector<Info> infos(seq_len);
    for (int i = 0; i < n_seqs; i++) {
        for (int j = 0; j < seq_len; j++) {
            char c;
            cin >> c;
            Info& info = infos[j];
            int& freq = ++info.freq_map[c];
            if (freq > info.max_freq || (freq == info.max_freq && c < info.max_freq_char)) {
                info.max_freq = freq;
                info.max_freq_char = c;
            }
        }
    }

    int dist = 0;
    for (Info& info : infos) {
        cout << info.max_freq_char;
        dist += n_seqs - info.max_freq;
    }
    cout << '\n' << dist << '\n';
}