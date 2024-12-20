#include <iostream>
#include <queue>

struct Pos
{
    int y;
    int x;
};

const int DYS[] = {1, 0, -1, 0};
const int DXS[] = {0, 1, 0, -1};

int maze_height, maze_width;
char maze[201][201];

const char m_wall = 'W';
const char m_empty = '.';
const char m_piece = 'P';

int calc_score(const Pos& dest, int n_pieces)
{
    static int visited[201][201];
    static int nx_visit_id = 1;

    std::queue<Pos> q({dest});
    int visit_id = visited[dest.y][dest.x] = nx_visit_id++;

    int dist = 0;
    int dist_sum = 0;

    size_t q_size;
    while ((q_size = q.size()))
    {
        while (q_size--)
        {
            const auto [y, x] = q.front();
            q.pop();

            if (maze[y][x] == m_piece)
            {
                dist_sum += dist;
                if (!--n_pieces)
                    return dist_sum;
            }

            for (int d = 0; d < 4; d++)
            {
                int ny = y + DYS[d];
                int nx = x + DXS[d];

                if (ny <= 0 || ny > maze_height || nx <= 0 || nx > maze_width
                || maze[ny][nx] == m_wall || visited[ny][nx] == visit_id)
                    continue;
                
                visited[ny][nx] = visit_id;
                q.push({ny, nx});
            }
        }
        dist++;
    }

}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_tc;
    std::cin >> n_tc;

    while (n_tc--)
    {
        std::cin >> maze_height >> maze_width;

        int n_pieces;
        std::cin >> n_pieces;

        Pos dest;
        std::cin >> dest.y >> dest.x;

        std::vector<Pos> pieces(n_pieces);

        for (int i = 0; i < n_pieces; i++)
            std::cin >> pieces[i].y >> pieces[i].x;

        std::vector<Pos> walls;
        
        for (int y = 1; y <= maze_height; y++)
        {
            for (int x = 1; x <= maze_width; x++)
            {
                char c;
                std::cin >> c;
                maze[y][x] = c;
                if (c == 'W')
                    walls.push_back({y, x});
            }
        }

        for (const Pos& piece : pieces)
            maze[piece.y][piece.x] = m_piece;

        int og_score = calc_score(dest, n_pieces);

        int wall_value_sum = 0;
        for (const Pos& wall : walls)
        {
            maze[wall.y][wall.x] = m_empty;

            int score = calc_score(dest, n_pieces);
            int wall_value = og_score - score;
            wall_value_sum += wall_value;

            maze[wall.y][wall.x] = m_wall;
        }

        std::cout << og_score << ' ' << wall_value_sum << '\n';
    }
}