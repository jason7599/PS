#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B, C;
    cin >> A >> B >> C;

    vector<int> a(A), b(B), c(C);
    for (int i = 0; i < A; i++) {
        cin >> a[i]; 
    }
    for (int i = 0; i < B; i++) {
        cin >> b[i]; 
    }
    for (int i = 0; i < C; i++) {
        cin >> c[i]; 
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    int i = 0, j = 0, k = 0;
    int min_diff = INT_MAX;

    while (i < A && j < B && k < C) {
        int x = a[i], y = b[j], z = c[k];
        int cur_max = max({x, y, z});
        int cur_min = min({x, y, z});
        
        min_diff = min(min_diff, cur_max - cur_min);

        if (cur_min == x) {
            i++; 
        } else if (cur_min == y) {
            j++;
        } else {
            k++;
        }
    }

    cout << min_diff << '\n';
}
