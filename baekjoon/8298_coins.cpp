#include <iostream>
#include <map>

// first and last appearance 
struct Info
{
    int first = -1;
    int last = -1;
};

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_coins, heads_diff;
    std::cin >> n_coins >> heads_diff;

    // <prefix, idx>
    std::map<int, Info> prefix_idx_map;

    // hax
    prefix_idx_map[0].first = -1;

    int prefix = 0;
    int ans = 0;
    for (int idx = 0; idx < n_coins; idx++)
    {
        char c;
        std::cin >> c;

        prefix += (c == 'O' ? 1 : -heads_diff);

        if (prefix_idx_map.count(prefix))
        {
            Info& info = prefix_idx_map.at(prefix);
            info.last = idx;
            ans = std::max(ans, info.last - info.first);
        }
        else
            prefix_idx_map[prefix].first = idx;
    }
    
    std::cout << ans;
}