#include <bits/stdc++.h>

bool check(const std::vector<int>& platforms, int exit_pos, int min_dist, int n_remove)
{
    int last_pos = 0;

    for (int platform : platforms)
    {
        int jump_dist = platform - last_pos;
        if (jump_dist < min_dist)
        {
            if (!n_remove--)
                return 0;
        }
        else
            last_pos = platform;
    }

    return exit_pos - last_pos >= min_dist;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int exit_pos, n_platforms, n_remove;
    std::cin >> exit_pos >> n_platforms >> n_remove;

    std::vector<int> platforms(n_platforms);

    for (int i = 0; i < n_platforms; i++)
        std::cin >> platforms[i];

    std::sort(platforms.begin(), platforms.end());

    int low = 0;
    int high = exit_pos;
    int ans;

    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (check(platforms, exit_pos, mid, n_remove)) // [mid, high]
        {
            ans = mid;
            low = mid + 1;
        }
        else // [low, mid)
            high = mid - 1;
    }

    std::cout << ans << '\n';
}