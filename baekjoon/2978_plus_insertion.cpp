#include <bits/stdc++.h>

int dp[1001][5001];
size_t ans[1001];

int solve(const std::string &num_str, int target_val, size_t idx = 0)
{
    if (idx == num_str.length())
    {
        if (target_val)
            return INT_MAX;
        return 0;
    }

    if (dp[idx][target_val] != -1)
        return dp[idx][target_val];

    size_t og_idx = idx;

    int sum = 0;
    int min_splits = INT_MAX - 1;
    size_t split_idx;
    for (; idx < num_str.length(); idx++)
    {
        int nx_sum = sum * 10 + (num_str.at(idx) - '0');
        if (nx_sum > target_val)
            break;

        sum = nx_sum;

        int t = solve(num_str, target_val - sum, idx + 1);
        if (t != INT_MAX)
        {
            if (t < min_splits)
            {
                min_splits = t;
                split_idx = idx;
            }
        }
    }

    min_splits++;

    if (min_splits != INT_MAX)
        ans[og_idx] = split_idx;

    return dp[og_idx][target_val] = min_splits;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::string num_str;
    int target_val;
    {
        std::string line;
        std::cin >> line;

        size_t t = line.find('=');

        num_str = line.substr(0, t);
        target_val = std::stoi(line.substr(t + 1));
    }

    for (size_t i = 0; i < num_str.length(); i++)
        std::fill(&dp[i][0], &dp[i][target_val + 1], -1);

    assert(solve(num_str, target_val) != INT_MAX);

    size_t idx = 0;
    while (idx < num_str.length())
    {
        size_t off = ans[idx];

        for (; idx <= off; idx++)
            std::cout << num_str.at(idx);

        if (idx != num_str.length())
            std::cout << '+';

    }
    std::cout << '=';
    std::cout << target_val << '\n';
}
