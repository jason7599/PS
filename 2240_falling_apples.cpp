#include <bits/stdc++.h>

int solve(const std::vector<int>& drops, size_t drop_idx, int pos, int n_moves)
{
    static int cache[1000][2][30];

    if (drop_idx == drops.size())
        return 0;
    
    if (cache[drop_idx][pos][n_moves])
        return std::max(cache[drop_idx][pos][n_moves], 0);
    
    int res = solve(drops, drop_idx + 1, pos, n_moves);
    if (n_moves)
        res = std::max(res, solve(drops, drop_idx + 1, !pos, n_moves - 1));
    
    res += (pos + 1) == drops[drop_idx];

    cache[drop_idx][pos][n_moves] = res ? res : -1;
    return res;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int n_drops, n_moves;
    std::cin >> n_drops >> n_moves;

    std::vector<int> drops(n_drops);
    for (int& drop : drops)
        std::cin >> drop;

    std::cout << std::max(solve(drops, 0, 0, n_moves), solve(drops, 0, 1, n_moves - 1)) << '\n';
}