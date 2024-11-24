#include <iostream>

const int MAX_VAL = 100'000;

struct Coin
{
    int val;
    int cnt;
};

int n_coins;
Coin coins[100];

bool solve(int iter, int target_val, int idx = 0)
{
    // memo[iter][target_val][idx]
    // 0 : not cached, 1 : true, -1 : false
    static char memo[3][MAX_VAL / 2 + 1][100];

    if (!target_val)
        return 1;
    
    if (idx == n_coins)
        return 0;
    
    if (memo[iter][target_val][idx])
        return memo[iter][target_val][idx] == 1;

    const Coin& coin = coins[idx];

    bool res = 0;

    for (int cnt = 0; cnt <= coin.cnt; cnt++)
    {
        if (target_val < coin.val * cnt)
            break;
        
        if (solve(iter, target_val - coin.val * cnt, idx + 1))
        {
            res = 1;
            break;
        }
    }

    memo[iter][target_val][idx] = res ? 1 : -1;

    return res;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    for (int tc = 0; tc < 3; tc++)
    {
        std::cin >> n_coins;
        
        int sum = 0;
        for (int i = 0; i < n_coins; i++)
        {
            int val, cnt;
            std::cin >> val >> cnt;
            coins[i].val = val;
            coins[i].cnt = cnt;
            sum += val * cnt;
        }

        std::cout << (sum % 2 == 0 && solve(tc, sum / 2)) << '\n';
    }
}