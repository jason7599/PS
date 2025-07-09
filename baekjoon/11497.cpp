#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int n, arr[10'000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_tc;
    cin >> n_tc;
    while (n_tc--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
    }
}