#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

pii f(const vector<int>& spots, int log_len, int max_len, int n_cuts) {
    int last_cut = log_len;
    for (int i = spots.size() - 1; i >= 0; i--) {
        if (last_cut - spots[i] > max_len) {
            if (i + 1 == spots.size() || spots[i + 1] - spots[i] > max_len || !n_cuts--) {
                return {-1, 0};
            }
            last_cut = spots[i + 1];
        }
    }
    return {last_cut, n_cuts};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int log_len, n_spots, n_cuts;
    cin >> log_len >> n_spots >> n_cuts;

    vector<int> spots(n_spots + 1);
    for (int i = 1; i <= n_spots; i++) {
        cin >> spots[i];
    }
    spots.front() = 0;

    sort(spots.begin(), spots.end());

    pii ans;
    for (int l = 1, r = log_len - 1; l <= r;) {
        int m = (l + r) >> 1;
        auto [c, b] = f(spots, log_len, m, n_cuts);
        if (c != -1) {
            ans = {m, b ? spots[1] : c};
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << ans.first << ' ' << ans.second << '\n';
}