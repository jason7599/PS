#include <iostream>
#include <algorithm>

int n_students, min_diff;
int height[16];

int64_t solve(int mask, int prev_student = -1)
{
    static int64_t memo[1 << 16][16];

    if (mask == (1 << n_students) - 1)
        return 1;

    if (prev_student != -1 && memo[mask][prev_student])
    {
        if (memo[mask][prev_student] == -1)
            return 0;
        return memo[mask][prev_student];
    }
    
    int64_t res = 0;
    for (int i = 0; i < n_students; i++)
    {
        if (((mask >> i) & 1) == 0) // n vwwwwwwwwwwwwww
        {
            if (prev_student == -1 
            || std::abs(height[prev_student] - height[i]) > min_diff)
                res += solve(mask | (1 << i), i);
        } 
    }

    if (prev_student != -1)
        memo[mask][prev_student] = res ? res : -1;
    return res;
}

int main()
{
    std::cin >> n_students >> min_diff;
    for (int i = 0; i < n_students; i++)
        std::cin >> height[i];
    std::cout << solve(0);
}