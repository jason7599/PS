#include <iostream>
#include <algorithm>

#define M 1000001
#define INF 987654321

using namespace std;

int n;
int dp[M];
int nxt[M];

int func(int x) {

    if (dp[x]) return dp[x];
    if (x == 1) return 0;

    int res1 = func(x - 1);
    int res2 = x % 2 ? INF : func(x / 2);
    int res3 = x % 3 ? INF : func(x / 3);

    int res = min(res1, min(res2, res3));

    if (res == res1) nxt[x] = x - 1;
    else if (res == res2) nxt[x] = x / 2;
    else if (res == res3) nxt[x] = x / 3;

    return dp[x] = res + 1;
}

int main() {
    cin >> n;
    cout << func(n) << '\n';
    for (int c = n; c; cout << c << ' ', c = nxt[c]);
}