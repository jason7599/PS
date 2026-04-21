#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

bool check(const vector<int>& arr, int c, int min_dist) {
    c--;
    for (int i = 1, b = 0; i + c <= arr.size(); i++) {
        if (arr[i] - arr[b] >= min_dist) {
            b = i;
            if (!--c) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, c;
    cin >> n >> c;

    vector<int> arr(n);
    for (int& i : arr) {
        cin >> i;
    }
    sort(arr.begin(), arr.end());

    int ans;
    for (int l = 0, r = arr.back() - arr.front(); l <= r;) {
        int m = (l + r) >> 1;
        if (check(arr, c, m)) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << ans << '\n';
}
