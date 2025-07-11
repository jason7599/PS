#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

/**
 * 
 */

int n, csum[1001], dp[1001];

int g(int s, int e) {
    return csum[e] - csum[s - 1];
}

int g(int n) {
    return g(n, n);
}

int b(int i) {
    int res;
    for (res = i; res + 1 <= n && g(i, res) >= g(res + 1); res++);
    return res;
}

int f(int i) {
    if (i == n + 1) {
        return 0;
    }

    int& res = dp[i];
    if (res) {
        return res;
    }

    int nxt = b(i); // can collapse nxt with the push of i

    res = f(nxt + 1); // remove i ~ nxt
    int sum = g(i, nxt);

    for (nxt += 2; nxt <= n && sum < g(nxt); nxt++);
    if (nxt <= n) {
        
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> csum[i];
        csum[i] += csum[i - 1];
    }


}