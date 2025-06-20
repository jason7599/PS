#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

bool check(const vector<int>& stops, int n_new, int max_gap) {
    int prev = 0;
    for (int stop : stops) {
        int gap = stop - prev;
        if (gap > max_gap) {
            int n_req = (gap + max_gap - 1) / max_gap - 1;
            if (n_new < n_req) {
                return 0;
            }
            n_new -= n_req;
        }
        prev = stop;
    }
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n_stop, n_new, road_len;
    cin >> n_stop >> n_new >> road_len;

    vector<int> stops(n_stop + 1);
    for (int i = 0; i < n_stop; i++) {
        cin >> stops[i];
    }
    stops.back() = road_len;

    sort(stops.begin(), stops.end());

    int ans;
    for (int l = 1, r = road_len; l <= r;) {
        int m = (l + r) >> 1;
        if (check(stops, n_new, m)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << ans << '\n';
}
