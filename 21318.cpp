#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n, arr[100'001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    int p;
    cin >> p;
    for (int i = 2, c = 0; i <= n; i++) {
        int x;
        cin >> x;
        if (x < p) {
            c++;
        }
        arr[i] = c;
        p = x;
    }

    int n_q;
    cin >> n_q;
    while (n_q--) {
        int a, b;
        cin >> a >> b;
        cout << arr[b] - arr[a] << '\n';
    }
}