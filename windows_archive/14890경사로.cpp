#include <iostream>

using namespace std;

int map_size, ramp_len;
int map[100][100];
bool ramp_placed[100][100];

bool try_place_ramp(int start_y, int start_x, int dy, int dx, int length, int height)
{
    int y = start_y;
    int x = start_x;
    for (int i = 0; i < length; i++)
    {
        if (y < 0 || y >= map_size || x < 0 || x >= map_size
        || ramp_placed[y][x])// ||)

        y += dy;
        x += dx;
    }
}

bool check_path(int start_y, int start_x, int dy, int dx)
{
    int height = map[start_y][start_x];
    int y = start_y + dy;
    int x = start_x + dx;
    while (y < map_size && x < map_size)
    {
        int n_height = map[y][x];
        switch (n_height - height)
        {
            case 1:

        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> map_size >> ramp_len;

    for (int y = 0; y < map_size; y++)
    {
        for (int x = 0; x < map_size; x++)
            cin >> map[y][x];
    }


}