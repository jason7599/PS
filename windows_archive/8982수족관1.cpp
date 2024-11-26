#include <iostream>

using namespace std;

#define MAX_CORNERS 5000

struct Floor
{
    int start_x;
    int width;
    int depth;
    int surface_depth;
};

int num_floors;
Floor floors[MAX_CORNERS / 2 - 1];

int total_water;

void debug()
{
    cout << ":::[DEBUG]:::\n\n";

    int depth = 0;
    bool stop = false;

    do
    {
        stop = true;
        cout << depth << " |";

        for (int i = 0; i < num_floors; i++)
        {
            Floor floor = floors[i];
            char c;

            if (floor.depth == depth)
                c = '_';
            else if (floor.depth < depth)
                c = '#';
            else
            {
                stop = false;

                if (floor.surface_depth == depth)
                    c = '~';
                else if (floor.surface_depth < depth)
                    c = ' ';
                else
                    c = ' ';
            }

            for (int j = 0; j < floor.width; j++)
                cout << c;
        }

        cout << "|\n";
        depth++;

    } while (!stop);

    cout << "\n total water: " << total_water << '\n';
}

int find_floor_index(int start_x)
{
    int l = 0, r = num_floors - 1, m;

    while (l <= r)
    {
        m = (l + r) / 2;

        if (floors[m].start_x == start_x)
            return m;
        
        if (floors[m].start_x < start_x)
            l = m + 1;
        else 
            r = m - 1;
    }

    return -1;
}

void lower_surface(int floor_index, int target_surface_depth)
{
    int depth_delta = target_surface_depth - floors[floor_index].surface_depth;

    if (depth_delta <= 0) return;

    floors[floor_index].surface_depth = target_surface_depth;
    total_water -= depth_delta * floors[floor_index].width;
}

void drain_floor(int floor_index)
{
    int depth = floors[floor_index].depth;
    int drain_depth = depth;

    lower_surface(floor_index, drain_depth);

    for (int i = floor_index + 1; i < num_floors; i++)
    {
        if (floors[i].depth < drain_depth)
            drain_depth = floors[i].depth;
        
        lower_surface(i, drain_depth);
    }

    drain_depth = depth;
    for (int i = floor_index - 1; i >= 0; i--)
    {
        if (floors[i].depth < drain_depth)
            drain_depth = floors[i].depth;
        
        lower_surface(i, drain_depth);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int num_corners;
    cin >> num_corners;

    num_floors = num_corners / 2 - 1;

    int temp;
    cin >> temp >> temp; // 0 0

    for (int i = 0; i < num_floors; i++)
    {
        int start_x, depth;
        cin >> start_x >> temp; // start_x, depth
        cin >> temp >> depth; // end_x, depth

        floors[i] = {start_x, temp - start_x, depth, 0};
        
        total_water += (temp - start_x) * depth;
    }

    cin >> temp >> temp; // _, 0

    int num_holes;
    cin >> num_holes;

    for (int i = 0; i < num_holes; i++)
    {
        int start_x;
        cin >> start_x >> temp >> temp >> temp;
        drain_floor(find_floor_index(start_x));
        // debug();
    }

    cout << total_water;

    // debug();
}