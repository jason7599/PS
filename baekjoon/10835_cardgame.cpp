#include <iostream>
#include <algorithm>

int n_cards;

// 0: left, 1: right
// smaller idx closer to top
int deck[2][2000];

int solve(int l_top = 0, int r_top = 0)
{
    static int memo[2000][2000];

    if (l_top == n_cards || r_top == n_cards)
        return 0;

    if (memo[l_top][r_top])
        return std::max(memo[l_top][r_top], 0);

    // 1. discard l
    int res = solve(l_top + 1, r_top);

    // 2. discard both
    res = std::max(res, solve(l_top + 1, r_top + 1));

    if (deck[0][l_top] > deck[1][r_top])
        res = std::max(res, deck[1][r_top] + solve(l_top, r_top + 1));
    
    memo[l_top][r_top] = res ? res : -1;
    return res;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> n_cards;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n_cards; j++)
            std::cin >> deck[i][j];
    }

    std::cout << solve();
}