#include <iostream>
#include <queue>

/**
 * n x n grid
 * rain of death (rod) on every tile except:
 *  start pos: S
 *  safe pos: E
 * rod depletes hp by 1 every turn
 * 
 * K x Umbrellas(U) in grid
 * each U has D durability
 * destroyed upon reaching 0
 * 
 * only up to 10 umbrellas!! bitmasking? yup.
 * but keeping a visited array of 
 * [500][500][1024][5000] would be disastrously large.
 * instead maybe we can take out the durability part
 * by doing an iteration every umbrella we get
 */

struct Pos
{
    int y, x;
};

struct State
{
    Pos pos;
    int hp;
    int umbrella_hp;
    int umbrella_mask;
    int time;
};

const int dys[] = {1, 0, -1, 0};
const int dxs[] = {0, 1, 0, -1};

int map_size;
int map[500][500];
int umbrella_durability;

const int t_empty = -1;
const int t_start = -2;
const int t_dest = -3;

bool is_oob(int y, int x)
{
    return y < 0 || y >= map_size || x < 0 || x >= map_size;
}

int solve(const State& init_state)
{
    static bool visited[500][500][1024];
    std::queue<State> q;

    visited[init_state.pos.y][init_state.pos.x][0] = 1;
    q.push(init_state);

    while (!q.empty())
    {
        const State& cur_state = q.front();
        q.pop();

        std::queue<State> m_q({cur_state});
        while (!m_q.empty())
        {
            const auto [pos, hp, umbrella_hp, umbrella_mask, time] = m_q.front();
            m_q.pop();

            for (int d = 0; d < 4; d++)
            {
                int ny = pos.y + dys[d];
                int nx = pos.x + dxs[d];

                if (is_oob(ny, nx))
                    continue;
                
                
            }
        }
    }
}

int main()
{
    int init_hp;
    std::cin >> map_size >> init_hp >> umbrella_durability;

    int n_umbrellas = 0;
    Pos start_pos;
    for (int y = 0; y < map_size; y++)
    {
        for (int x = 0; x < map_size; x++)
        {
            char c;
            std::cin >> c;

            int t;

            switch (c)
            {
            case 'S':
                start_pos = {y, x};
                t = t_start;
                break;
            
            case 'U':
                t = n_umbrellas++;
                break;
            
            case 'E':
                t = t_dest;
                break;
            
            case '.':
                t = t_empty;
                break;
            }

            map[y][x] = t;
        }
    }

    std::cout << solve(State{start_pos, init_hp, 0, 0, 0});
}