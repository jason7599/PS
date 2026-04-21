#include <iostream>
#include <vector>
#include <algorithm>

struct Point
{
    int y, x;  
};

bool is_valid(const std::vector<Point>& points, int size, int min_x, int min_y)
{
    int max_x = min_x + size;
    int max_y = min_y + size;

    for (const auto& [y, x] : points)
    {
        if (!(x == min_x || x == max_x || y == min_y || y == max_y))
            return 0;
    }
    return 1;
}

int main()
{
    int n_points;
    std::cin >> n_points;
    std::vector<Point> points(n_points);

    int min_x = 1000, max_x = -1000;
    int min_y = 1000, max_y = -1000;

    for (Point& p : points)
    {
        int x, y;
        std::cin >> x >> y;

        p.x = x, p.y = y;

        min_x = std::min(min_x, x);
        max_x = std::max(max_x, x);
        min_y = std::min(min_y, y);
        max_y = std::max(max_y, y);
    }

    int size = std::max(max_x - min_x, max_y - min_y);

    // Test all possible square placements
    // all possible bottom left corner positions.
    std::vector<std::pair<int, int>> candidates = {
        {min_x, min_y},
        {min_x, max_y - size},
        {max_x - size, min_y},
        {max_x - size, max_y - size}};

    for (const auto &candidate : candidates)
    {
        int min_x = candidate.first;
        int min_y = candidate.second;
        if (is_valid(points, size, min_x, min_y))
        {
            std::cout << size;
            return 0;
        }
    }

    std::cout << -1;
}
