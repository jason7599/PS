#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

bool fuck(const vector<int>& arr, int v, int i) {
    if (i == arr.size()) {
        return 1;
    }
    int t = upper_bound(arr.begin() + i, arr.end(), v) - arr.begin();
    if (t == arr.size()) {
        return 1;
    }
    if (v + t - i <= arr[t]) {
        return 0;
    }
    return fuck(arr, v + t - i, t);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& i : arr) {
        cin >> i;
    }

    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }

    bool none = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            continue;
        }
        int v = arr[i] + i;
        if (fuck(arr, v, i + 1)) {
            none = 0;
            cout << i + 1 << ' ';
        }
    }

    if (none) {
        cout << -1;
    }
    cout << '\n';
}
