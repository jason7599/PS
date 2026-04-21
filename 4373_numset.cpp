#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int n, arr[1000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    while (1) {
        cin >> n;
        if (!n) {
            break;
        }
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
    }
}