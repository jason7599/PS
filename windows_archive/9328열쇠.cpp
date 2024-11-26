#include <iostream>
#include <string>
#include <queue>

#define pii pair<int,int>

using namespace std;

const char map_wall = '*';
const char map_empty = '.';
const char map_docs = '$';

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int map_height, map_width;
char map[100][100];
bool visited[100][100];
bool has_key[26];
vector<pii> door_locs_in_path[26];
queue<pii> traverse_q;
int docs_stolen;

bool is_key(char c)
{
    return 'a' <= c && c <= 'z';
}

bool is_door(char c)
{
    return 'A' <= c && c <= 'Z';
}

void on_key_obatined(char key)
{
    has_key[key - 'a'] = true;
    for (pii door_loc : door_locs_in_path[key - 'a'])
    {
        traverse_q.push(door_loc);
        visited[door_loc.first][door_loc.second] = true;
    }
}

void input()
{
    docs_stolen = 0;

    cin >> map_height >> map_width;
    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            visited[y][x] = false;

            char c; cin >> c;
            if (!y || !x || y == map_height - 1 || x == map_width - 1)
            {
                if (c == map_empty)
                {
                    traverse_q.push({y, x});
                    visited[y][x] = true;
                }
                else if (c == map_docs)
                {
                    docs_stolen++;
                    traverse_q.push({y, x});
                    visited[y][x] = true;
                }
                else if (is_door(c))
                {
                    int door_index = c - 'A';
                    if (!has_key[door_index])
                        door_locs_in_path[door_index].push_back({y, x});
                    else
                    {
                        traverse_q.push({y, x});    
                        visited[y][x] = true;
                    }
                }
                else if (is_key(c))
                {
                    if (!has_key[c - 'a'])
                        on_key_obatined(c);
                    traverse_q.push({y, x});
                    visited[y][x] = true;
                }
            }

            map[y][x] = c;
        }
    }

    string start_keys; cin >> start_keys;
    if (start_keys != "0")
    {
        for (char key : start_keys)
            on_key_obatined(key);
    }
}

int solve()
{

    while (!traverse_q.empty())
    {
        int y = traverse_q.front().first;
        int x = traverse_q.front().second;
        traverse_q.pop();

        for (int d = 0; d < 4; d++)
        {
            int ny = y + dy[d];
            int nx = x + dx[d];

            if (ny < 0 || ny == map_height || nx < 0 || nx == map_width
            || visited[ny][nx] || map[ny][nx] == map_wall)
                continue;
            
            if (map[ny][nx] == map_empty)
            {
                visited[ny][nx] = true;
                traverse_q.push({ny, nx});
            }
            else if (is_door(map[ny][nx]))
            {
                int door_index = map[ny][nx] - 'A';
                if (has_key[door_index])
                {
                    visited[ny][nx] = true;
                    traverse_q.push({ny, nx});
                }
                else
                {
                    door_locs_in_path[door_index].push_back({ny, nx});
                }
            }
            else if (is_key(map[ny][nx]))
            {
                int key_index = map[ny][nx] - 'a';
                if (!has_key[key_index])
                    on_key_obatined(map[ny][nx]);
                visited[ny][nx] = true;
                traverse_q.push({ny, nx});
            }
            else if (map[ny][nx] == map_docs)
            {
                docs_stolen++;
                visited[ny][nx] = true;
                traverse_q.push({ny, nx});
            }
        }
    }

    return docs_stolen;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    int num_inputs; cin >> num_inputs;
    while (num_inputs--)
    {
        input();
        cout << solve() << '\n';
        // ans.push_back(solve());

        for (int i = 0; i < 26; i++)
        {
            has_key[i] = false;
            door_locs_in_path[i].clear();   
        }
    }

    // cout << "\n=======ans=-====\n";
    // for (int i : ans)
    // {
    //     cout << i << '\n';
    // }
}