#include <bits/stdc++.h>

int solve(const std::vector<int>& choice_max, size_t idx, int start_val)
{
    if (idx == choice_max.size())
        return 1;
    
    int res = 0;
    for (int val = start_val; val <= choice_max[idx]; val++)
        res += solve(choice_max, idx + 1, val * 2);
    
    return res;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n_tc;
    std::cin >> n_tc;

    while (n_tc--)
    {
        int n_choose, max_val;
        std::cin >> n_choose >> max_val;

        std::vector<int> choice_max(n_choose);
        choice_max.back() = max_val;
        for (int i = n_choose - 2; i >= 0; i--)
            choice_max[i] = choice_max[i + 1] >> 1;
        
        std::cout << solve(choice_max, 0, 1) << '\n';
    }
}