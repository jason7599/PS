#include <iostream>
#include <unordered_map>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_tc;
    std::cin >> n_tc;

    for (int tc = 1; tc <= n_tc; tc++)
    {
        int n_elems;
        std::cin >> n_elems;

        std::unordered_map<int, int> prefix_sums; // sum: freq
        prefix_sums[0] = 1;

        int sum = 0;
        int min_neg_sum = 0;
        long long ans = 0;

        for (int i = 0; i < n_elems; i++)
        {
            int val;
            std::cin >> val;
            
            sum += val;
            min_neg_sum = std::min(min_neg_sum, sum);

            for (int j = 0; sum - j * j >= min_neg_sum; j++)
            {
                if (prefix_sums.count(sum - j * j))
                    ans += prefix_sums.at(sum - j * j);
            }

            prefix_sums[sum]++;
        }

        std::cout << "Case #" << tc << ": " << ans << '\n';
    }
}