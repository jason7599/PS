#include <iostream>
#include <algorithm>

const int mod = 1e9;

int solve(int len, int start, int mask)
{
    static int memo[101][10][1 << 10];

    if (len == 1)
        return mask == (1 << 10) - 1;
    
    if (memo[len][start][mask])
        return std::max(memo[len][start][mask], 0);
    
    int res = 0;
    if (start)
        res = solve(len - 1, start - 1, mask | (1 << (start - 1)));
    if (start != 9)
        res = (res + solve(len - 1, start + 1, mask | (1 << (start + 1)))) % mod;
    
    memo[len][start][mask] = res ? res : -1;
    return res;
}

int main()
{
    int len;
    std::cin >> len;
    int ans = 0;
    for (int s = 1; s <= 9; s++)
        ans = (ans + solve(len, s, 1 << s)) % mod;
    std::cout << ans; 
}