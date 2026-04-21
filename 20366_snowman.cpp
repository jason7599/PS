#include <bits/stdc++.h>
using namespace std;

int n, arr[600];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int ans = INT_MAX;

    for (int i = 0; i < n - 3; i++) {
        for (int j = i + 3; j < n; j++) {
            int target = arr[i] + arr[j];
            for (int l = i + 1, r = j - 1; l < r;) {
                int sum = arr[l] + arr[r];
                if (sum == target) {
                    cout << 0 << '\n';
                    return 0;
                }
                if (sum > target) {
                    r--;
                } else {
                    l++;
                }
                ans = min(ans, abs(target - sum));
            }
        }
    }

    cout << ans << '\n';
}
