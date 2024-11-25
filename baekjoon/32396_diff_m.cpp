#include <iostream>

const int inf = -1;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_elems;
    u_int64_t min_diff;
    std::cin >> n_elems >> min_diff;

    int ans = 0;
    u_int64_t prev;
    std::cin >> prev;
    for (int i = 1; i < n_elems; i++)
    {
        u_int64_t x;
        std::cin >> x;

        if (prev != inf)
        {
            u_int64_t diff = x > prev ? x - prev : prev - x;
            if (diff < min_diff)
            {
                ans++;
                x = inf;
            }
        }

        prev = x;
    }

    std::cout << ans;
}