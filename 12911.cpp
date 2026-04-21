#include <iostream>
#include <algorithm>

const int mod = 1e9 + 7;

int seq_len, max_val;
int dp[11][100'001];
int sum[11];

int main()
{
    std::cin >> seq_len >> max_val;

    // dp[1][1 ~ max_val] = 1
    std::fill(dp[1] + 1, dp[1] + max_val + 1, 1);

    sum[1] = max_val; // sum[len] = n of arrs with length <= len

    for (int len = 2; len <= seq_len; len++)
    {
        for (int mv = 1; mv <= max_val; mv++)
        {
            int temp  = 0;
            for (int k = 2 * mv; k <= max_val; k += mv)
                temp = (temp + dp[len - 1][k]) % mod; 

            dp[len][mv] = sum[len - 1] - temp;
            if (dp[len][mv] < 0)
                dp[len][mv] += mod;
            
            sum[len] = (sum[len] + dp[len][mv]) % mod;
        }
    }

    std::cout << sum[seq_len];
}