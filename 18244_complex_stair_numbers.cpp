#include <iostream>
#include <algorithm>

const int mod = 1e9 + 7;

/**
 * should not contain a sequence that increases or decreases
 * of length 3: can only increase/decrease up length 2
 */
int solve(int len, int start, int asc, int desc)
{
    static int memo[101][10][3][3];

    if (len == 1)
        return 1;
    
    if (memo[len][start][asc][desc])
        return std::max(memo[len][start][asc][desc], 0);

    int res = 0;
    if (asc != 2 && start != 9)
        res = solve(len - 1, start + 1, asc + 1, 0);
    if (desc != 2 && start)
        res = (res + solve(len - 1, start - 1, 0, desc + 1)) % mod;
    
    memo[len][start][asc][desc] = (res ? res : -1);
    return res;
}

int main()
{
    int len;
    std::cin >> len;
    int ans = 0;
    for (int start = 0; start <= 9; start++)
        ans = (ans + solve(len, start, 0, 0)) % mod;
    std::cout << ans;
}