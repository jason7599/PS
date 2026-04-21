#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int n, arr[200'000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int x;
    cin >> n >> x;
    x--;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll max_score = 0, score = 0;
    for (int l = x - 1, r = x + 1; score >= 0;) {
        while (l >= 0 && arr[l] >= 0) {
            score += arr[l--];
        }
        while (r < n && arr[r] >= 0) {
            score += arr[r++];
        }

        max_score = max(max_score, score);

        int nx_l = l;
        

        // if (l == -1) {
        //     if (r == n) {
        //         break;
        //     }
        //     score += arr[r++];
        // } else {
        //     if (r == n || arr[l] > arr[r]) {
        //         score += arr[l--];
        //     } else {
        //         score += arr[r++];
        //     }
        // }
    }

    cout << max_score << '\n';
}