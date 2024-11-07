#include <iostream>

double dp[101][10]; // dp[len][start]

double get_tight_word_ratio(const int max_val, int start, int length)
{
    if (length == 1)
        return 1;

    if (dp[length][start])
        return dp[length][start];

    double res = get_tight_word_ratio(max_val, start, length - 1);
    int tight_branch_cnt = 1;
    if (start != max_val)
    {
        res += get_tight_word_ratio(max_val, start + 1, length - 1);
        tight_branch_cnt++;
    }
    if (start != 0)
    {
        res += get_tight_word_ratio(max_val, start - 1, length - 1);
        tight_branch_cnt++;
    }
    
    return dp[length][start] = res * (max_val + 1 - tight_branch_cnt);
}

int main()
{
    std::cout << std::fixed;
    std::cout.precision(5);

    while (!std::cin.eof())
    {
        int max_val, length;
        std::cin >> max_val >> length;

        std::fill_n(dp[1], length * 10, 0);

        
    }
}