#include <iostream>
#include <algorithm>

int num_people;
int prices[15][15];

inline bool visited(int vmask, int p)
{
    return vmask >> p & 1;
}

inline void set_visited(int& vmask, int p)
{
    vmask |= 1 << p;
}

int solve(int p_idx, int prev_price, int vmask)
{
    static int memo[15][10][(1 << 15) - 1];

    set_visited(vmask, p_idx);

    if (memo[p_idx][prev_price][vmask])
        return memo[p_idx][prev_price][vmask];

    int res = 0;
    for (int other = 0; other < num_people; other++)
    {   
        if (other != p_idx 
        && prices[p_idx][other] >= prev_price 
        && !visited(vmask, other))
            res = std::max(res,
            solve(other, prices[p_idx][other], vmask));
    }

    return memo[p_idx][prev_price][vmask] = 1 + res;
}

int main()
{
    std::cin >> num_people;
    for (int i = 0; i < num_people; i++)
    {
        for (int j = 0; j < num_people; j++)
        {
            char c;
            std::cin >> c;
            prices[i][j] = c - '0';
        }
    }

    std::cout << solve(0, 0, 0);
}