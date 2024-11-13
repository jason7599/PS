#include <iostream>
#include <algorithm>

const int mod = 1e9 + 9;

int solve(int n, int m)
{
    static int memo[1001][1001];

    if (!n)
        return 1;

    if (n < 0 || !m)
        return 0;

    if (memo[n][m])
        return std::max(memo[n][m], 0);
    
    int res = 0;
    for (int i = 1; i <= 3; i++)
        res = (res + solve(n - i, m - 1)) % mod;

    memo[n][m] = res ? res : -1;
    return res;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        int n, m;
        std::cin >> n >> m;
        std::cout << solve(n, m) << '\n';
    }
}