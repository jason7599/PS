#include <iostream>
#include <algorithm>

int board[2][401];

/**
 * dp[c][i][j]: 열 c까지 고려했을때:
 *  첫번째 행에서 숫자 i개를 썼을 때
 *  두번째 행에서 숫자 j개를 썼을 때
 * 최댓값.
 */
int dp[401][401][401];
 
int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_cols, nz_cnt[2] = {0};
    std::cin >> n_cols;
 
    for (int r = 0; r < 2; r++)
    {
        for (int c = 0; c < n_cols; c++)
        {
            int x; 
            std::cin >> x;
            if (x)
                board[r][++nz_cnt[r]] = x;
        }
    }
    
    for (int c = 1; c <= n_cols; c++)
    {
        for (int i = 1; i <= std::min(nz_cnt[0], c); i++)
        {
            for (int j = 1; j <= std::min(nz_cnt[1], c); j++)
            {
                if (i == c && c == j) // 걍 다 붙여서 곱하는 거.
                    dp[c][i][j] = 
                        dp[c - 1][i - 1][j - 1] + board[0][i] * board[1][j];
                else if (i == c)
                    dp[c][i][j] = std::max(dp[c - 1][i - 1][j],
                        dp[c - 1][i - 1][j - 1] + board[0][i] * board[1][j]
                    );
                
            }
        }
    }
}
