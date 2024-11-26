#include <iostream>
#include <queue>

using namespace std;

const int max_archers = 3;

const int dy[] = {0, -1, 0};
const int dx[] = {1, 0, -1};

int map_height, map_width;
int init_enemy_count;
bool enemies[15][15];
int max_shoot_dist;
int max_score;

void solve();
bool try_shoot_enemy(int,int,pair<int,int>&);
int simulate_score(const vector<int>&);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> map_height >> map_width >> max_shoot_dist;

    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            cin >> enemies[y][x];
            if (enemies[y][x])
                init_enemy_count++;
        }
    }

    solve();
    cout << max_score;
}


void solve()
{
    static vector<int> archers_pos;
    static int pos = 0;

    if (archers_pos.size() == max_archers)
    {
        int score = simulate_score(archers_pos);
        if (score > max_score)
            max_score = score;
        return;
    }

    if (pos == map_width)
        return;

    archers_pos.push_back(pos++);
    solve();
    archers_pos.pop_back();
    solve();
    pos--;
}


int simulate_score(const vector<int>& archers_pos)
{
    vector<pair<int,int>> killed;

    int advance = 0;
    int i = 0;
    int kills = 0;
    while (advance < map_height && kills != init_enemy_count)
    {
        for (int archer_pos : archers_pos)
        {
            pair<int,int> hit_pos;
            if (try_shoot_enemy(archer_pos, advance, hit_pos))
                killed.push_back(hit_pos);
        }
        while (i < killed.size())
        {
            if (enemies[killed[i].first][killed[i].second])
            {
                enemies[killed[i].first][killed[i].second] = false;
                kills++;
            }
            i++;
        }
        advance++;
    }

    for (pair<int,int> kill : killed)
        enemies[kill.first][kill.second] = true;

    return kills;
}


bool try_shoot_enemy(int archer_pos, int enemy_advance, pair<int,int>& hit_pos)
{
    bool visited[15][15] = {false};
    queue<pair<int,int>> q;

    int start_row = map_height - enemy_advance - 1;

    if (enemies[start_row][archer_pos])
    {
        hit_pos = {start_row, archer_pos};
        return true;
    }

    visited[start_row][archer_pos] = true;
    q.push({start_row, archer_pos});

    bool hit = false;

    for (int dist = 1; dist < max_shoot_dist; dist++)
    {
        int i = q.size();
        while (i--)
        {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for (int d = 0; d < 3; d++)
            {
                int ny = y + dy[d];
                int nx = x + dx[d];

                if (ny < 0 || nx < 0 || nx >= map_width || visited[ny][nx])
                    continue;
                
                if (enemies[ny][nx])
                {
                    if (hit)
                    {
                        if (nx < hit_pos.second)
                            hit_pos = {ny, nx};
                    }
                    else
                    {
                        hit = true;
                        hit_pos = {ny, nx};
                    }
                }

                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }

        if (hit)
            break;
    }

    return hit;
}
