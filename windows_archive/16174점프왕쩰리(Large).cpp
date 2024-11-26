#include <iostream>
#include <queue>

using namespace std;

int map_size;
int map[64][64];

bool is_possible()
{
    bool visited[64][64] = {0};
    queue<pair<int, int>> q;

    visited[0][0] = true;
    q.push({0, 0});

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        int jump = map[y][x];
        if (jump == -1)
            return true;

        if (y + jump < map_size && !visited[y + jump][x])
        {
            visited[y + jump][x] = true;
            q.push({y + jump, x});
        }
        if (x + jump < map_size && !visited[y][x + jump])
        {
            visited[y][x + jump] = true;
            q.push({y, x + jump});
        }
    }

    return false;
}

int main()
{
    cin >> map_size;

    for (int y = 0; y < map_size; y++)
        for (int x = 0; x < map_size; x++)
            cin >> map[y][x];

    if (is_possible())
        cout << "HaruHaru";
    else
        cout << "Hing";

    return 0;
}