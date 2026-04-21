#include <iostream>
#include <queue>
#include <map>

const int MAX_MAP_SIZE = 2000;

const std::map<char, int> CHAR_DIRS =
{
    {'U', 0},
    {'D', 1},
    {'L', 2},
    {'R', 3}
};

// U, D, L, R
const int MOVES[4][2] = 
{
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

struct Pos
{
    int y;
    int x;
};

struct MazeCell
{
    int dir;
    int jump_cost;
};

int maze_height, maze_width;
MazeCell maze[MAX_MAP_SIZE][MAX_MAP_SIZE];

int n_visit_id = 1;
int visited[MAX_MAP_SIZE][MAX_MAP_SIZE];

int ans;

void dfs(int y, int x, std::vector<Pos>& path, int visit_id = -1)
{
    // std::cout << "at {" << y << ", " << x << "}, visit_id = " << visit_id << ", path = ";
    // for (Pos pos : path)
    //     std::cout << '{' << pos.y << ", " << pos.x << "} ";
    // std::cout << '\n';

    if (visited[y][x])
    {
        if (visited[y][x] == visit_id) // loop!
        {
            int min_cost = 1e9;
            for (size_t i = path.size() - 1;; i--) // sus
            {
                min_cost = std::min(min_cost, maze[path[i].y][path[i].x].jump_cost);
                if (path[i].y == y && path[i].x == x) // only the loop itself
                    break;
            }

            ans += min_cost;
            // std::cout << min_cost << '\n';
        }

        // else: this path converges with another path, whose cost has already been accounted for
        return;
    }

    // init
    if (visit_id == -1)
        visit_id = n_visit_id++;
    
    visited[y][x] = visit_id;
    path.push_back({y, x});

    int ny = y + MOVES[maze[y][x].dir][0];
    int nx = x + MOVES[maze[y][x].dir][1];

    if (ny < 0 || ny >= maze_height || nx < 0 || nx >= maze_width)
        return;
    
    dfs(ny, nx, path, visit_id);
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> maze_height >> maze_width;

    for (int y = 0; y < maze_height; y++)
    {
        for (int x = 0; x < maze_width; x++)
        {
            char c;
            std::cin >> c;
            maze[y][x].dir = CHAR_DIRS.at(c);
        }
    }

    for (int y = 0; y < maze_height; y++)
    {
        for (int x = 0; x < maze_width; x++)
            std::cin >> maze[y][x].jump_cost;
    }

    for (int y = 0; y < maze_height; y++)
    {
        for (int x = 0; x < maze_width; x++)
        {
            std::vector<Pos> ass;
            dfs(y, x, ass);
        }
    }

    std::cout << ans;
}
