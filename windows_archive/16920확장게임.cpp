#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

struct Player
{
    char num;               // the char representation of the player number, eg '1', '2', ...
    int expand_dist;        // how many tiles can this player expand in one expansion iteration 
    queue<pii> expand_q;    // queue of coords that are ready to be checked for expansion 
    int tile_count;         // number of tiles this player has "conquered"
};

const char tile_empty = '.';
const char tile_wall = '#';

int map_height, map_width;
char map_tiles[1000][1000];

/**
 * denotes whether a coord has been on a player's expand_q.
 * to prevent duplicate coords pushed to the expand_q on a single expansion iteration 
 */
bool visited[1000][1000]; 

/**
 * on a single expansion iteration, bfs is done for each coord present in expand_q.
 * within a single expansion iteration, therefore, multiple bfs iterations can cross paths, and this should be allowed.
 * but it should not be allowed in a single bfs iteration to go back to a coord it just visited.
 * traverse_visited is used to distinguish these two scenarios, by marking the coords a unique traverse_id every bfs iteration.
 * the same effect could be achieved by creating a new false-initialized visited matrix every bfs iteration, but it would probably suffer performance-wise.  
 */
int traverse_visited[1000][1000];
int traverse_next_id = 1;

int num_players;
Player players[9];


void print_players();
void print_map();
void expand(Player* player);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> map_height >> map_width >> num_players;

    for (int i = 0; i < num_players; i++)
    {
        players[i].num = i + '1';
        cin >> players[i].expand_dist;
    }

    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            char c; cin >> c;
            map_tiles[y][x] = c;
            if (c != tile_empty && c != tile_wall)
            {
                Player* player = &players[c - '1'];
                player->expand_q.push({y, x});
                player->tile_count++;

                visited[y][x] = true;
            }
        }
    }

    while (true)
    {
        bool finish = true;
        for (int i = 0; i < num_players; i++)
        {
            Player* player = &players[i];
            expand(player);
            if (!player->expand_q.empty())
                finish = false;
        }
        if (finish)
            break;
    }

    print_map();

    for (int i = 0; i < num_players; i++)
        cout << players[i].tile_count << ' ';

    return 0;
}


void expand(Player* player)
{
    const int dys[] = {1, 0, -1, 0};
    const int dxs[] = {0, 1, 0, -1};

    int expand_q_size = player->expand_q.size();
    while (expand_q_size--)
    {
        int traverse_id = traverse_next_id++;

        int start_y = player->expand_q.front().first;
        int start_x = player->expand_q.front().second;
        player->expand_q.pop();

        queue<pii> traverse_q;
        traverse_q.push({start_y, start_x});
        traverse_visited[start_y][start_x] = traverse_id;
        
        int traverse_dist = 0;
        int traverse_q_size;

        while ((traverse_q_size = traverse_q.size()) != 0 
            && traverse_dist++ < player->expand_dist)
        {
            while (traverse_q_size--)
            {
                int y = traverse_q.front().first;
                int x = traverse_q.front().second;
                traverse_q.pop();

                for (int d = 0; d < 4; d++)
                {
                    int ny = y + dys[d];
                    int nx = x + dxs[d];

                    if (ny < 0 || ny >= map_height  || nx < 0 || nx >= map_width
                    || (map_tiles[ny][nx] != tile_empty && map_tiles[ny][nx] != player->num)) // skip wall tiles and other players' tiles
                        continue;

                    if (traverse_visited[ny][nx] != traverse_id)
                    {
                        traverse_visited[ny][nx] = traverse_id;
                        traverse_q.push({ny, nx}); 
                    }

                    if (!visited[ny][nx])
                    {
                        visited[ny][nx] = true;
                        map_tiles[ny][nx] = player->num;

                        player->expand_q.push({ny, nx});
                        player->tile_count++;
                    }
                }
            }
        }
    }
}

void print_players()
{
    for (int i = 0; i < num_players; i++)
    {
        Player player = players[i];
        cout << "Player " << player.num << ":\n";
        cout << "\texpand_dist = " << player.expand_dist << '\n';
        cout << "\ttile_count = " << player.tile_count << '\n';
    }
}

void print_map()
{
    cout << "\nPRINT_MAP\n";
    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            cout << map_tiles[y][x];
        }
        cout << '\n';
    }
    cout << '\n';
}