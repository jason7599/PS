#include <iostream>
#include <queue>

// u r d l
const int dys[] = {-1, 0, 1, 0};
const int dxs[] = {0, 1, 0, -1};

int maze_height, maze_width;
int maze[50][50];

struct State
{
    int y, x;
    int n_l_turns;
    int n_r_turns;
};

bool& visited(State state)
{
    static bool _visited[50][50][151][151];
    return _visited[state.y][state.x][state.n_l_turns][state.n_r_turns];
}

bool can_escape(int n_turns)
{
    visited({0, 0, n_turns, n_turns}) = 1;
    std::queue<State> q({{0, 0, n_turns, n_turns}});

    while (!q.empty())
    {
        const auto& [y, x, n_l_turns, n_r_turns] = q.front();
        q.pop();

        if (y == maze_height - 1 && x == maze_width - 1)
            return 1;
        
        
    }

    return 0.;
}

int main()
{
    int n_turns;
    std::cin >> maze_height >> maze_width;
    std::cin >> n_turns;

    for (int y = 0; y < maze_height; y++)
    {
        for (int x = 0; x < maze_width; x++)
        {
            char c;
            std::cin >> c;
            int t;
            switch (c)
            {
            case 'U': t = 0; break;
            case 'R': t = 1; break;
            case 'D': t = 2; break;
            case 'L': t = 3; break;
            }
            maze[y][x] = t;
        }
    }


}