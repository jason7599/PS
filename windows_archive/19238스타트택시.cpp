#include <iostream>
#include <queue>

using namespace std;

// 0: empty,
// 1: impassable,
// n >= 2: starting point of passenger of index n - 2
int map[21][21];
int map_size;
int fuel_left;
int taxi_y, taxi_x;

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

bool out_of_bounds(int, int);
int try_drive_to_nearest_passenger();
bool try_drive_to_destination(pair<int,int>);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int num_passengers;
    pair<int,int> passenger_destinations[20 * 20];

    cin >> map_size >> num_passengers >> fuel_left;

    for (int y = 1; y <= map_size; y++)
    {
        for (int x = 1; x <= map_size; x++)
        {
            cin >> map[y][x];
        }
    }

    cin >> taxi_y >> taxi_x;

    for (int i = 0; i < num_passengers; i++)
    {
        int start_y, start_x, dest_y, dest_x;
        cin >> start_y >> start_x >> dest_y >> dest_x;

        map[start_y][start_x] = i + 2;
        passenger_destinations[i] = {dest_y, dest_x};
    }

    for (int i = 0; i < num_passengers; i++)
    {
        int p;
        if ((p = try_drive_to_nearest_passenger()) < 0 || !try_drive_to_destination(passenger_destinations[p]))
        {
            fuel_left = -1;
            break;
        }
    }

    cout << fuel_left;
}

bool try_drive_to_destination(pair<int,int> dest)
{
    bool visited[21][21] = {false};
    queue<pair<int,int>> q;
    int fuel_exhausted = 0;

    visited[taxi_y][taxi_x] = true;
    q.push({taxi_y, taxi_x});

    int q_size;
    while ((q_size = q.size()))
    {
        while (q_size--)
        {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            if (y == dest.first && x == dest.second)
            {
                fuel_left += fuel_exhausted;
                taxi_y = y;
                taxi_x = x;
                return true;
            }

            for (int d = 0; d < 4; d++)
            {
                int ny = y + dy[d];
                int nx = x + dx[d];

                if (out_of_bounds(ny, nx) || map[ny][nx] == 1 || visited[ny][nx])
                    continue;
                
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }

        if (++fuel_exhausted > fuel_left)
            return false;
    }

    return false;
}

// if fuel sufficent, drive to and returns the index of the nearest passenger
// else return -1
int try_drive_to_nearest_passenger()
{
    bool visited[21][21] = {false};
    queue<pair<int,int>> q;

    visited[taxi_y][taxi_x] = true;
    q.push({taxi_y, taxi_x});

    int q_size;
    while ((q_size = q.size()))
    {
        int nearest_passenger_y = 0;
        int nearest_passenger_x = 0;

        while (q_size--)
        {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            if (map[y][x] > 1)
            {
                if (!nearest_passenger_y || y < nearest_passenger_y || (y == nearest_passenger_y && x < nearest_passenger_x))
                {
                    nearest_passenger_y = y;
                    nearest_passenger_x = x;
                }
                continue;
            }

            for (int d = 0; d < 4; d++)
            {
                int ny = y + dy[d];
                int nx = x + dx[d];

                if (out_of_bounds(ny, nx) || map[ny][nx] == 1 || visited[ny][nx])
                    continue;
                
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
        if (nearest_passenger_y)
        {
            int passenger_index = map[nearest_passenger_y][nearest_passenger_x] - 2;
            map[nearest_passenger_y][nearest_passenger_x] = 0;
            taxi_y = nearest_passenger_y;
            taxi_x = nearest_passenger_x;
            return passenger_index;
        }

        if (--fuel_left <= 0)
            return -1;
    }
    return -1;
}

bool out_of_bounds(int y, int x)
{
    return y < 1 || y > map_size || x < 1 || x > map_size;
}