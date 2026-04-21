#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int len, arr[5000];

bool check(int max_diff, int n_groups) {
    int min_elem = arr[0], max_elem = arr[0];
    for (int i = 1; i < len; i++) {
        min_elem = min(min_elem, arr[i]);
        max_elem = max(max_elem, arr[i]);

        if (max_elem - min_elem > max_diff) {
            if (!--n_groups) {
                return 0;
            }
            min_elem = max_elem = arr[i];
        }
    }

    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_groups;
    cin >> len >> n_groups;

    int min_elem = 10'000, max_elem = 1;
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
        min_elem = min(min_elem, arr[i]);
        max_elem = max(max_elem, arr[i]);
    }

    int ans;
    for (int l = 0, r = max_elem - min_elem; l <= r;) {
        int m = (l + r) >> 1;
        if (check(m, n_groups)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << ans << '\n';
}