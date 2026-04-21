#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n_tc;
    cin >> n_tc;
    while (n_tc--) {
        string str;
        int k;
        cin >> str >> k;

        unordered_map<char, vector<int>> char_idxs;
        for (int i = 0; i < str.length(); i++) {
            char_idxs[str[i]].push_back(i);
        }

        int ans0 = INT_MAX; // shortest len
        int ans1 = 0;       // longest len with both ends equal
        for (const auto& [c, idxs] : char_idxs) {
            if (idxs.size() < k) {
                continue;
            }
            for (int i = k - 1; i < idxs.size(); i++) {
                int len = idxs[i] - idxs[i - k + 1] + 1;
                ans0 = min(ans0, len);
                ans1 = max(ans1, len);
            }
        }

        if (ans0 == INT_MAX) {
            cout << -1;
        } else {
            cout << ans0 << ' ' << ans1;
        }
        cout << '\n';
    }
}