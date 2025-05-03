#include <bits/stdc++.h>
using namespace std;

int64_t bs_mult(int a, int b) {
    int64_t res = 0;
    for (int64_t d = 1; a || b; a /= 10, b /= 10) {
        int n = (a ? (a % 10) : 1) * (b ? (b % 10) : 1);
        if (!n) {
            d *= 10;
        } else for (; n; n /= 10, d *= 10) {
            res += (n % 10) * d;
        }
    }
    return res;
}

bool check(int a, int b) {
    int64_t real = (int64_t)a * b; 
    int64_t bs = bs_mult(a, b);
    return real == bs; 
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n_tc;
    cin >> n_tc;
    while (n_tc--) {
        int a, b;
        cin >> a >> b;
        cout << check(a, b) << '\n';
    }
}