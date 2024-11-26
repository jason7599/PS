#include <iostream>
#include <vector>

#define MAX_MAP_SIZE 100

using namespace std;

int map_size_x; // row. bigger = lower
int map_size_y; // col
bool minerals[MAX_MAP_SIZE][MAX_MAP_SIZE];

const int DX[] = {-1, 0, 1, 0};
const int DY[] = {0, 1, 0, -1};
const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;

void throw_spear(int, bool);
void spear_hit(int, int);
bool out_of_bounds(int, int);
int get_fall_distance_from(int, int);
void print_map();

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> map_size_x >> map_size_y;

    for (int x = 0; x < map_size_x; x++)
    {
        for (int y = 0; y < map_size_y; y++)
        {
            char c; cin >> c;
            minerals[x][y] = c == 'x';
        }
    }

    int num_throw; cin >> num_throw;

    for (int t = 0; t < num_throw; t++)
    {
        int throw_height; cin >> throw_height;
        throw_spear(map_size_x - throw_height, t % 2 == 0);
    }

    print_map();
}

void throw_spear(int spear_x, bool leftside)
{
    int spear_y;
    int spear_dy;

    if (leftside)
    {
        spear_y = 0;
        spear_dy = DY[RIGHT];
    }
    else
    {
        spear_y = map_size_y - 1;
        spear_dy = DY[LEFT];
    }

    int t;
    for (t = 0; t < map_size_y; t++)
    {
        if (minerals[spear_x][spear_y])
        {
            break;
        }
        spear_y += spear_dy;
    }

    if (t < map_size_y)
    {
        spear_hit(spear_x, spear_y);
    }
}

void spear_hit(int hit_x, int hit_y)
{
    minerals[hit_x][hit_y] = false;

    bool visited[MAX_MAP_SIZE][MAX_MAP_SIZE] = { false };

    for (int init_dir = 0; init_dir < 4; init_dir++)
    {
        int init_nx = hit_x + DX[init_dir];
        int init_ny = hit_y + DY[init_dir];

        if (!out_of_bounds(init_nx, init_ny) && minerals[init_nx][init_ny] && !visited[init_nx][init_ny])
        {
            visited[init_nx][init_ny] = true;

            vector<pair<int, int>> cluster;
            cluster.push_back({init_nx, init_ny});
            int queue_front = 0;

            while (queue_front < cluster.size())
            {
                int cur_x = cluster.at(queue_front).first;
                int cur_y = cluster.at(queue_front++).second;

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur_x + DX[dir];
                    int ny = cur_y + DY[dir];

                    if (!out_of_bounds(nx, ny) && minerals[nx][ny] && !visited[nx][ny])
                    {
                        visited[nx][ny] = true;
                        cluster.push_back({nx, ny});
                    }
                }
            }

            // calculate min fall distance, if equal to 0, continue, else fall

            for (pair<int, int> xy : cluster)
            {
                minerals[xy.first][xy.second] = false;
            }

            int min_fall_distance = map_size_x; // init max val

            for (pair<int,int> xy : cluster)
            {
                int fall_distance = get_fall_distance_from(xy.first, xy.second);

                if (fall_distance < min_fall_distance)
                {
                    min_fall_distance = fall_distance;

                    if (fall_distance == 0)
                    {
                        break;
                    }
                }
            }

            for (pair<int, int> xy : cluster)
            {
                minerals[xy.first + min_fall_distance][xy.second] = true;
            }

            if (min_fall_distance)
                return;
        }
    }
}

int get_fall_distance_from(int x, int y)
{
    int fall_distance = 0;
    int nx = x;

    while (1)
    {
        nx += DX[DOWN];

        if (nx >= map_size_x || minerals[nx][y])
            break;

        fall_distance++;
    }

    return fall_distance;
}

bool out_of_bounds(int x, int y)
{
    return x < 0 || x >= map_size_x || y < 0 || y >= map_size_y;
}

void print_map()
{
    for (int x = 0; x < map_size_x; x++)
    {
        for (int y = 0; y < map_size_y; y++)
        {
            cout << (minerals[x][y] ? 'x' : '.');
        }
        cout << '\n';
    }
}
