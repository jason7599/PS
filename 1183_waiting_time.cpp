#include <bits/stdc++.h>
#define PRINT(x) {cout << x << '\n';}
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int n, diff[50];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        diff[i] = a - b;
    }

    if (n % 2) {
        PRINT(1)
    } else {
        sort(diff, diff + n);
        PRINT(diff[n / 2] - diff[n / 2 - 1] + 1)
    }
}