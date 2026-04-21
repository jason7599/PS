#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    ull n;
    cin >> n;
    for (; n % 2 == 0; n >>= 1);

    if (!++n) {
        cout << 64 << '\n';
        return 0;
    }

    int k = 0;
    for (; n != 1; n >>= 1, k++);

    cout << k << '\n';
}