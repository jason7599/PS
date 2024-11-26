#include <iostream>
#include <set>

#define coord pair<int,int>

using namespace std;

// clockwise starting from south
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

set<coord> visited_relative_coords;
int min_relative_x, max_relative_x;
int min_relative_y, max_relative_y;

bool visited_absolute_coords[51][51];

void mark_relative_coords()
{
    int num_moves;
    cin >> num_moves;

    int current_relative_x = 0;
    int current_relative_y = 0;
    int current_direction = 0;

    visited_relative_coords.insert(coord{current_relative_x, current_relative_y});

    while (num_moves--)
    {
        char move;
        cin >> move;

        switch (move)
        {
            case 'L':
            current_direction = (current_direction + 3) % 4;
            break;

            case 'R':
            current_direction = (current_direction + 1) % 4;
            break;

            case 'F':
            current_relative_x += dx[current_direction];
            current_relative_y += dy[current_direction];

            if (visited_relative_coords.insert(coord{current_relative_x, current_relative_y}).second)
            {
                if (current_relative_x < min_relative_x) min_relative_x = current_relative_x;
                if (current_relative_x > max_relative_x) max_relative_x = current_relative_x;
                if (current_relative_y < min_relative_y) min_relative_y = current_relative_y;
                if (current_relative_y > max_relative_y) max_relative_y = current_relative_y;
            }
        }
    }
}

void mark_absolute_coords()
{
    for (coord relative_coord : visited_relative_coords)
    {
        visited_absolute_coords[relative_coord.first - min_relative_x][relative_coord.second - min_relative_y] = true;
    }
}

void print_absolute_map()
{
    int map_size_x = max_relative_x - min_relative_x + 1;
    int map_size_y = max_relative_y - min_relative_y + 1;

    for (int x = 0; x < map_size_x; x++)
    {
        for (int y = 0; y < map_size_y; y++)
        {
            cout << (visited_absolute_coords[x][y] ? '.' : '#');
        }
        cout << '\n';
    }
}

int main()
{
    mark_relative_coords();
    mark_absolute_coords();
    print_absolute_map();
}