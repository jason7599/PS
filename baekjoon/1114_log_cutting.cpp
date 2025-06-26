#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int total_len, n_spots, n_cuts;
int spots[10'000];

int f(int max_len) {
    int prev = 0;
    int t = n_cuts;
    int r = -1;

    for (int i = 0; i < n_spots; i++) {
        if (spots[i] - prev >= max_len) {
            if (!t--) {
                return -1;
            }
            prev = spots[i];
            if (r == -1) {
                r = spots[i];
            }
        }
    }

    if (total_len - prev >= max_len) {
        if (!t) {
            return -1;
        }
    }

    if (r == -1) {
        r = spots[0];
    }

    cout << "f(" << max_len << ") = " << r << '\n'; 

    return r;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> total_len >> n_spots >> n_cuts;
    for (int i = 0; i < n_spots; i++) {
        cin >> spots[i];
    }

    sort(spots, spots + n_spots);

    int ans;
    int ans2;
    for (int l = 1, r = total_len; l <= r;) {
        int m = (l + r) >> 1;
        int t = f(m);
        if (t != -1) {
            ans = m;
            ans2 = t;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << ans << ' ' << ans2 << '\n';
}
