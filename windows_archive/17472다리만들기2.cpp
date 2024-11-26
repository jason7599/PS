#include <iostream>
#include <queue>

#define MAX_MAP_SIZE 10
#define MAX_ISLAND_COUNT 6

#define SEA -1

using namespace std;

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

struct try_bridge
{
    int from_island;
    int direction;
    int from_y;
    int from_x;
};

int map_size_y, map_size_x;
int map[MAX_MAP_SIZE][MAX_MAP_SIZE];
int num_islands;
vector<try_bridge> try_bridges;
int root[MAX_ISLAND_COUNT];
int dist_matrix[MAX_ISLAND_COUNT][MAX_ISLAND_COUNT];

bool is_oob(int,int);
void print_map();
void label_islands();
void update_dist_matrix();
int get_minimum_bridge_length();
int find_set(int);

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> map_size_y >> map_size_x;

    for (int y = 0; y < map_size_y; y++)
    {
        for (int x = 0; x < map_size_x; x++)
        {
            int t; cin >> t;
            map[y][x] = t - 1; // -1: SEA, 0: island. 
        }
    }

    label_islands();
    update_dist_matrix();
    // print_map();
    cout << get_minimum_bridge_length();
}

bool is_oob(int y, int x)
{
    return y < 0 || y >= map_size_y || x < 0 || x >= map_size_x;
}

// label each island and store bridge starting point candidates
void label_islands()
{
    bool visited[10][10] = { false };
    int next_island_id = 0;

    for (int y = 0; y < map_size_y; y++)
    {
        for (int x = 0; x < map_size_x; x++)
        {
            if (map[y][x] == SEA || visited[y][x])
                continue;

            int island_id = next_island_id++;

            queue<pair<int,int>> q;
            q.push({y, x});
            visited[y][x] = true;

            while (!q.empty())
            {
                int this_y = q.front().first;
                int this_x = q.front().second;
                q.pop();

                map[this_y][this_x] = island_id;

                for (int d = 0; d < 4; d++)
                {
                    int ny = this_y + dy[d];
                    int nx = this_x + dx[d];

                    if (is_oob(ny, nx)) continue;
                    
                    if (map[ny][nx] == SEA)
                    {
                        try_bridges.push_back(try_bridge{island_id, d, ny, nx});
                        continue;
                    }

                    if (visited[ny][nx]) continue;

                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
        }
    }

    num_islands = next_island_id;
}

// try all the bridges, and keep track of min distance matrix
void update_dist_matrix()
{
    for (try_bridge tb : try_bridges)
    {
        int y = tb.from_y;
        int x = tb.from_x;

        int bridge_len = 0;
        int bridge_to = -1;

        while (true)
        {
            bridge_len++;

            y += dy[tb.direction];
            x += dx[tb.direction];

            if (is_oob(y, x))
                break;

            if (map[y][x] != SEA)
            {
                bridge_to = map[y][x];
                break;
            }
        }

        if (bridge_len >= 2 && bridge_to != -1 && bridge_to != tb.from_island)
        {
            if (!dist_matrix[tb.from_island][bridge_to] || bridge_len < dist_matrix[tb.from_island][bridge_to])
            {
                dist_matrix[tb.from_island][bridge_to] = dist_matrix[bridge_to][tb.from_island] = bridge_len;
            }
        }
    }
}

int get_minimum_bridge_length()
{
    int res = 0;
    //                 len,  from,  to
    priority_queue<pair<int,pair<int,int>>> pq;

    for (int i = 0; i < num_islands; i++)
    {
        for (int j = i + 1; j < num_islands; j++)
        {
            if (dist_matrix[i][j])
                pq.push({-dist_matrix[i][j], {i, j}});
        }
    }

    for (int i = 0; i < num_islands; i++)
        root[i] = i;

    while (!pq.empty())
    {
        int from = find_set(pq.top().second.first);
        int to = find_set(pq.top().second.second);

        if (from != to)
        {
            if (from < to) root[to] = from;
            else root[from] = to;

            res += -pq.top().first;
            // printf("connecting %d and %d len = %d\n", from, to, -pq.top().first);
        }
        
        pq.pop();
        // print_root();
    }

    for (int i = 1; i < num_islands; i++)
    {
        if (find_set(i) != 0)
            return -1;
    }

    return res;
}

int find_set(int x)
{
    if (x != root[x])
        root[x] = find_set(root[x]);
    return root[x];
}

void print_map()
{
    cout << "\nPrint Map\n";
    for (int y = 0; y < map_size_y; y++)
    {
        for (int x = 0; x < map_size_x; x++)
        {
            if (map[y][x] == SEA) cout << '_';
            else cout << map[y][x];
            cout << ' ';
        }
        cout << '\n';
    }
}

void print_root()
{
    cout << "Root:\n";
    for (int i = 0; i < num_islands; i++)
    {
        cout << i << '|';
    }
    cout << '\n';
    for (int i = 0; i < num_islands; i++)
    {
        cout << root[i] << ' ';
    }
    cout << '\n';
}
