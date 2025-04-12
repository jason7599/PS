#include <bits/stdc++.h>

using namespace std;

int64_t solve(int64_t n, int p, int q) {
    static unordered_map<int, int64_t> cache;

    if (!n) return 1;

    int64_t& res = cache[n];
    if (res) return res;

    return res = solve(n / p, p, q) + solve(n / q, p, q);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int64_t n, p, q;
    cin >> n >> p >> q;
    cout << solve(n, p, q) << '\n';
}