#include <iostream>
#include <algorithm>

const int MAX_GENERATORS = 16;
const int INF = 1e9;

int n_generators;
int fix_costs[MAX_GENERATORS][MAX_GENERATORS];

int solve(int on_mask, int fix_req)
{
    static int memo[1 << MAX_GENERATORS][MAX_GENERATORS];

    if (fix_req <= 0)
        return 0;

    if (memo[on_mask][fix_req])
        return std::max(memo[on_mask][fix_req], 0);
    
    int res = INF;

    for (int i = 0; i < n_generators; i++)
    {
        if (!(on_mask & (1 << i)))
            continue;
        
        for (int j = 0; j < n_generators; j++)
        {
            if (!(on_mask & (1 << j)))
                res = std::min(res,
                    fix_costs[i][j] + solve(on_mask | (1 << j), fix_req - 1));
        }
    }

    memo[on_mask][fix_req] = res ? res : -1;
    return res;
}

int main()
{
    std::cin >> n_generators;
    for (int i = 0; i < n_generators; i++)
    {
        for (int j = 0; j < n_generators; j++)
            std::cin >> fix_costs[i][j];
    }

    int on_mask = 0;
    int n_on = 0;
    for (int i = 0; i < n_generators; i++)
    {
        char c;
        std::cin >> c;
        if (c == 'Y')
        {
            on_mask |= 1 << i;
            n_on++;
        }
    }

    int n_min_fix;
    std::cin >> n_min_fix;

    int t = solve(on_mask, n_min_fix - n_on);
    std::cout << (t == INF ? -1 : t);
}