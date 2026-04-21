#include <iostream>
#include <algorithm>

const int mod = 1e9 + 9;

int solve(int n, bool even)
{
    static int memo[2][100'001];

    if (!n)
        return even;

    if (memo[even][n])
        return std::max(memo[even][n], 0);

    int res = 0;
    for (int i = 1; i <= std::min(n, 3); i++)
        res = (res + solve(n - i, !even)) % mod;
    
    memo[even][n] = res ? res : -1;
    return res;
}

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        std::cout << solve(n, 0) << ' ' << solve(n, 1) << '\n';
    }
}