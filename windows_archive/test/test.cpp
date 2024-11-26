#include <iostream>
#include <vector>
#include <tuple>

// Directions: up, down, left, right
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int h, w;
std::pair<int, int> start, end;
bool visited[8][8];
std::vector<std::pair<int, int>> path;

bool is_valid(int x, int y) {
    return x >= 0 && x < h && y >= 0 && y < w && !visited[x][y];
}

bool backtrack(int x, int y, int count) {
    if (x == end.first && y == end.second && count == h * w) {
        path.push_back({x, y});
        return true;
    }

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (is_valid(nx, ny)) {
            visited[nx][ny] = true;
            path.push_back({nx, ny});
            if (backtrack(nx, ny, count + 1)) return true;
            path.pop_back();
            visited[nx][ny] = false;
        }
    }

    return false;
}

int main() {

    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_tc;
    std::cin >> n_tc;
    while (n_tc--)
    {
        std::cin >> h >> w;

        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                visited[i][j] = 0;

        std::cin >> start.first >> start.second >> end.first >> end.second;

        start.first--, start.second--; // Convert to 0-based indexing
        end.first--, end.second--;

        visited[start.first][start.second] = true;
        path.push_back(start);

        if (backtrack(start.first, start.second, 1)) {
            std::cout << "YO !!!\n";
            for (auto &[x, y] : path) {
                std::cout << x + 1 << " " << y + 1 << "\n"; // Convert back to 1-based
            }
        } else {
            std::cout << "No path exists\n";
        }

        path.clear();
    }

    return 0;
}
