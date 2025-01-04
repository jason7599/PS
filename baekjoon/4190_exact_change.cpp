#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 1e9;
const int MAX_VAL = 10'000; // bill <= 10'000, so we shouldn't exceed this 

int main()
{
    int n_tc;
    std::cin >> n_tc;

    while (n_tc--)
    {
        int target; // <= 10'000
        std::cin >> target;

        int n_bills;
        std::cin >> n_bills;

        std::vector<int> bills(n_bills);
        for (int& bill : bills)
            std::cin >> bill;

        std::vector<int> dp(MAX_VAL, INF); // dp[n] = min number of bills to achieve value of n
        dp[0] = 0;
        
        for (int bill : bills)
        {
            for (int val = MAX_VAL; val >= bill; val--)
            {
                if (dp[val - bill] != INF)
                    dp[val] = std::min(dp[val], dp[val - bill] + 1);
            }
        }

        int min_val;
        for (min_val = target; dp[min_val] == INF; min_val++);

        std::cout << min_val << ' ' << dp[min_val] << '\n';
    }
    return 0;
}