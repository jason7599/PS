#include <iostream>

using namespace std;

int func(int dist, int n)
{
    static int memo[101][101];

    if (n == 1)
        return 1;

    if (memo[dist][n])
        return memo[dist][n];

    if (dist == 0)
        return memo[dist][n] = 2 * func(1, n - 1) % 10'007;
    
    int ans = 0;

    if (dist > 1)
        ans += func(dist - 1, n - 1) % 10'007;
    ans += 2 * func(dist, n - 1) % 10'007;
    ans += func(dist + 1, n - 1) % 10'007;

    return memo[dist][n] = ans % 10'007;
}

int main()
{
    int n; cin >> n;
    cout << func(0, n);
    return 0;
}