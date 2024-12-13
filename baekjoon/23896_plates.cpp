#include <iostream>
#include <algorithm>

int n_stacks, stack_size;
int stacks[50][30]; //[stack][index]. index = 0 = top

int cache[50][1501]; // -1: fucked, 0: not calculated, -2: zero
const int cache_uninit = 0;
const int cache_fucked = -1;

int get_max_beauty(int stack_idx, int take_cnt)
{
    if (stack_idx == n_stacks)
        return take_cnt ? cache_fucked : 0; // -1: didnt take enough, therefore invalid

    if (!take_cnt)
        return 0;

    int& res = cache[stack_idx][take_cnt];

    if (res)
        return res;
    
    bool fucked = 1; // got only -1s
    int sum = 0;
    for (int take = 0; take <= std::min(take_cnt, stack_size); take++)
    {
        if (take)
            sum += stacks[stack_idx][take - 1];

        int t = get_max_beauty(stack_idx + 1, take_cnt - take);
        if (t != cache_fucked)
        {
            fucked = 0;
            res = std::max(res, sum + t);
        }
    }

    if (fucked)
        return res = cache_fucked;

    return res;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_tc;
    std::cin >> n_tc;

    for (int tc = 1; tc <= n_tc; tc++)
    {
        int take_cnt;
        std::cin >> n_stacks >> stack_size >> take_cnt;

        for (int s = 0; s < n_stacks; s++)
        {
            std::fill(&cache[s][1], &cache[s][1 + take_cnt], cache_uninit);

            for (int p = 0; p < stack_size; p++)
                std::cin >> stacks[s][p];
        }

        std::cout << "Case #" << tc << ": ";
        std::cout << get_max_beauty(0, take_cnt) << '\n';
    }
}