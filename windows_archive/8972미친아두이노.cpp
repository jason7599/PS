#include <iostream>
#include <string>
#include <set>

using namespace std;
using pii = pair<int, int>;

/*
 *  7 8 9
 *  4 5 6
 *  1 2 3
*/
const int dys[] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
const int dxs[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int map_height, map_width;

int sign(int x)
{
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

pii calc_next_pos(pii robot, pii player)
{
    int dy = sign(player.first - robot.first);
    int dx = sign(player.second - robot.second);
    return {robot.first + dy, robot.second + dx};
}

void print_map(const set<pii>& robots, pii player)
{
    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            pii pos = {y, x};

            if (pos == player)
                cout << 'I';
            else if (robots.find(pos) != robots.end())
                cout << 'R';
            else
                cout << '.';
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> map_height >> map_width;

    pii player;
    set<pii> robots;

    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            char c; cin >> c;
            if (c == 'I')
                player = {y, x};
            else if (c == 'R')
                robots.insert({y, x});
        }
    }

    string player_moves;
    cin >> player_moves;

    int turn = 0;
    for (char c : player_moves)
    {
        turn++;

        player = {player.first + dys[c - '1'], player.second + dxs[c - '1']};
        
        set<pii> next_robots;
        set<pii> explosion;
        
        for (pii robot : robots)
        {
            // player moved into a robot
            if (robot == player)
            {
                cout << "kraj " << turn << '\n';
                return 0;
            }

            pii next_pos = calc_next_pos(robot, player);

            if (next_pos == player)
            {
                cout << "kraj " << turn << '\n';
                return 0;
            }

            if (next_robots.find(next_pos) == next_robots.end())
                next_robots.insert(next_pos);
            else
                explosion.insert(next_pos);
        }

        for (pii pos : explosion)
            next_robots.erase(pos);
        
        robots = next_robots;

        // cout << '\n';
        // cout << '\n';
    }

    // cout << "ROBOTS SIZE AHHHH " << robots.size() << '\n';
    // for (pii robot : robots)
    // {
    //     cout << '{' << robot.first << ' ' << robot.second << "}\n";
    // }

    print_map(robots, player);


    return 0;
}