#include <iostream>
#include <algorithm>

const int mod = 1e9 + 7;

int dp[200'001][5];

int main()
{
    int days;
    std::cin >> days;

    for (int i = 0; i < 5; i++)
        dp[1][i] = 1;

    for (int d = 2; d <= days; d++)
    {
        for (int i = 1; i < 5; i++)
        {
            dp[d][0] = (dp[d][0] + dp[d - 1][i]) % mod;
    
            for (int j = 0; j < 5; j++)
            {
                if (!j || std::abs(i - j) > 1)
                    dp[d][i] = (dp[d][i] + dp[d - 1][j]) % mod;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 5; i++)
        ans = (ans + dp[days][i]) % mod;
    std::cout << ans;
}