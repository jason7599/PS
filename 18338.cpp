#include <iostream>
#include <string>
#include <map>
#include <vector>

const std::map<char, std::pair<int, int>> dir_map = 
{
    {'U', {-1, 0}},
    {'D', {1, 0}},
    {'L', {0, -1}},
    {'R', {0, 1}}
};

int solve(const std::string& dirs, int y, int x, size_t i, std::vector<std::pair<int, int>> path)
{
    static bool visited[3][3];

    if (i == dirs.length())
    {
        std::cout << "\n====\n";
        for (auto [y, x] : path)
            std::cout << '{' << y << ", " << x << "}\n";
        std::cout << "\n====\n";

        return 1;
    }
    
    visited[y][x] = 1;
    
    auto [dy, dx] = dir_map.at(dirs[i]);

    int ny = y + dy;
    int nx = x + dx;

    int ans = 0;

    while (0 <= ny && ny < 3 && 0 <= nx && nx < 3 && !visited[ny][nx])
    {
        visited[ny][nx] = 1;
        path.push_back({ny, nx});
        ans += solve(dirs, ny, nx, i + 1, path);
        path.pop_back();
        ny += dy;
        nx += dx;
    }

    while (ny != y || nx != x)
    {
        ny -= dy;
        nx -= dx;
        visited[ny][nx] = 0;
    }

    return ans;
}

int solve(const std::string& dirs)
{
    int ans = 0;
    for (int i = 0; i < 9; i++)
        ans += solve(dirs, i / 3, i % 3, 0, {});
    return ans;
}

int main()
{
    std::string dirs;
    std::cin >> dirs;
    std::cout << solve(dirs);
}