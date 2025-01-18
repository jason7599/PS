#include <bits/stdc++.h>

int n_elems;
struct
{
    int val;
    int cost;
} elems[20];

int dp[20][101];

int solve(int idx, int rem)
{
    if (idx == n_elems)
        return 0;

    if (dp[idx][rem])
        return std::max(dp[idx][rem], 0);
    
    int res = solve(idx + 1, rem);
    if (elems[idx].cost < rem)
        res = std::max(res, elems[idx].val + solve(idx + 1, rem - elems[idx].cost));
    
    dp[idx][rem] = res ? res : -1;
    return res;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> n_elems;
    
    for (int i = 0; i < n_elems; i++)
        std::cin >> elems[i].cost;

    for (int i = 0; i < n_elems; i++)
        std::cin >> elems[i].val;

    std::cout << solve(0, 100);
}