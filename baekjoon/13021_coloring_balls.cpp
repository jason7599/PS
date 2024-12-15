#include <iostream>
#include <algorithm>
#include <set>

int balls[1001];

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_balls, n_strokes;
    std::cin >> n_balls >> n_strokes;

    for (int stroke = 1; stroke <= n_strokes; stroke++)
    {
        int l, r;
        std::cin >> l >> r;
        std::fill(&balls[l], &balls[r + 1], stroke);
    }

    auto colors = std::set<int>(balls + 1, balls + 1 + n_balls);
    int64_t ans = 1 << (colors.size() - colors.count(0));
    std::cout << ans;
}