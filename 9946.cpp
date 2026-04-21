#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

bool cmp(string& lhs, string& rhs) {
    if (lhs.length() != rhs.length()) {
        return 0;
    }
    int cnt[26] = {0};
    for (char c : lhs) {
        cnt[c - 'a']++;
    }
    for (char c : rhs) {
        if (!cnt[c - 'a']--) {
            return 0;
        }
    }
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    for (int i = 1;; i++) {
        string lhs, rhs;
        cin >> lhs >> rhs;
        if (lhs == "END" && lhs == rhs) {
            break;
        }
        cout << "Case " << i << ": " << (cmp(lhs, rhs) ? "same" : "different") << '\n';
    }
}
