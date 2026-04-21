#include <iostream>
#include <algorithm>

int num_cards;
int deck[100'000];

int get_score(int top, int count)
{
    int res = deck[top];
    for (int i = 1; i < count; i++)
        res ^= deck[top + i];
    
    int score = 0;
    while (res)
    {
        score += res % 2;
        res /= 2;
    }
    return score;
}

int solve(int top = 0)
{
    static int memo[100'000];

    int cards_left = num_cards - top;

    if (!cards_left)
        return 0;
    
    if (cards_left == 1)
    {
        // ! fucked.
        return -1;
    }

    if (memo[top])
        return std::max(memo[top], 0);

    int res = 0;
    int t = solve(top + 2);
    if (t != -1)
        res = get_score(top, 2) + t;
    
    if (cards_left > 2 && (t = solve(top + 3)) != -1)
        res = std::max(res, get_score(top, 3) + t);

    if (!res)
    {
        memo[top] = -1;
        return 0;
    }
    
    return memo[top] = res;
}

int main()
{
    std::cin >> num_cards;
    for (int i = 0; i < num_cards; i++)
        std::cin >> deck[i];
    
    std::cout << (num_cards < 2 ? 0 : solve());
}