#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <string>

#define LOG(x) std::cout << x << '\n';
#define NL std::cout << std::endl; 

using pii = std::pair<int, int>;

// u d l r
const int dys[] = {-1, 1, 0, 0};
const int dxs[] = {0, 0, -1, 1};

const std::string dnames[] = {"up", "down", "left", "right"};

int map_size;
bool roads[50][50];
int warrior_cnt[50][50]; // number of warrior_cnt in a given position
bool vision_map[4][50][50];

inline short sign(int x)
{
    if (!x) return 0;
    return x > 0 ? 1 : -1;
}

inline bool is_oob(int y, int x)
{
    return y < 0 || y >= map_size || x < 0 || x >= map_size;
}


std::string pii_to_str(pii p)
{
    return "{" + std::to_string(p.first) + ", " + std::to_string(p.second) + "}";
}

inline int get_distance(pii pos0, pii pos1)
{
    return std::abs(pos0.first - pos1.first) + std::abs(pos0.second - pos1.second);
}

std::vector<pii> get_path(pii start, pii dest)
{
    std::queue<std::vector<pii>> q;
    bool visited[50][50] = {0};

    q.push({start});
    visited[start.first][start.second] = 1;

    while (!q.empty())
    {
        std::vector<pii> path = q.front();
        q.pop();

        int y = path.back().first;
        int x = path.back().second;

        if (y == dest.first && x == dest.second)
            return path;
        
        for (int direction = 0; direction < 4; direction++)
        {
            int ny = y + dys[direction];
            int nx = x + dxs[direction];

            if (!is_oob(ny, nx) && roads[ny][nx] && !visited[ny][nx])
            {
                visited[ny][nx] = 1;
                std::vector<pii> new_path = path;
                new_path.push_back({ny, nx});
                q.push(new_path);
            }
        }
    }

    return {};
}

void mark_vision_map(pii start_pos, int direction, pii sight_range, bool vision)
{
    int y = start_pos.first + dys[direction];
    int x = start_pos.second + dxs[direction];
    int dist = 1;

    // std::cout << "mark vision " << vision << " from " << start_pos.first << ", " << start_pos.second << " with range " << sight_range.first << " ~ " << sight_range.second << '\n';

    while (!is_oob(y, x))
    {
        int y_fill_start, y_fill_end;
        int x_fill_start, x_fill_end;

        if (dys[direction]) // u, d
        {
            y_fill_start = y;
            y_fill_end = y;

            x_fill_start = std::max(0, x + dist * sight_range.first);
            x_fill_end = std::min(map_size - 1, x + dist * sight_range.second);
        }
        else
        {
            x_fill_start = x;
            x_fill_end = x;

            y_fill_start = std::max(0, y + dist * sight_range.first);
            y_fill_end = std::min(map_size - 1, y + dist * sight_range.second);
        }

        // LOG(y_fill_start)
        // LOG(y_fill_end)
        // LOG(x_fill_start)
        // LOG(x_fill_end)

        for (int fy = y_fill_start; fy <= y_fill_end; fy++)
        {
            for (int fx = x_fill_start; fx <= x_fill_end; fx++)
                vision_map[direction][fy][fx] = vision;
        }

        y += dys[direction];
        x += dxs[direction];
        dist++;
    }
}

void update_vision_map(pii medusa_pos, const std::set<pii>& warriors_pos, int direction)
{
    std::fill(&vision_map[direction][0][0], &vision_map[direction][map_size][0], 0);

    mark_vision_map(medusa_pos, direction, {-1, 1}, 1);

    for (pii warrior : warriors_pos)
    {
        if (vision_map[direction][warrior.first][warrior.second])
        {
            pii sight_range;

            if (dys[direction]) // u, d
            {
                if (medusa_pos.second < warrior.second)
                    sight_range = {0, 1};
                else if (medusa_pos.second == warrior.second)
                    sight_range = {0, 0};
                else
                    sight_range = {-1, 0};
            }
            else
            {
                if (medusa_pos.first < warrior.first)
                    sight_range = {0, 1};
                else if (medusa_pos.first == warrior.first)
                    sight_range = {0, 0};
                else
                    sight_range = {-1, 0};
            }

            mark_vision_map(warrior, direction, sight_range, 0);
        }
    }
}

pii get_warrior_next_pos(pii warrior, pii medusa, int medusa_direction, bool prioritize_y_movement)
{
    if (warrior == medusa)
        return warrior;

    int d = prioritize_y_movement ? 0 : 3;
    int dd = prioritize_y_movement ? 1 : -1;

    int closest_dist = 1e9;
    int best_direction = -1;

    for (int i = 0; i < 4; i++)
    {
        int ny = warrior.first + dys[d];
        int nx = warrior.second + dxs[d];

        if (!is_oob(ny, nx) && !vision_map[medusa_direction][ny][nx])
        {
            int dist = get_distance(medusa, {ny, nx});
            if (dist < closest_dist)
            {
                closest_dist = dist;
                best_direction = d;
            }
        }

        d += dd;
    }

    if (best_direction == -1)
        return warrior;

    return {warrior.first + dys[best_direction], warrior.second + dxs[best_direction]};
}

void DEBUG_print_state(pii medusa_pos, const std::set<pii>& warriors_pos, int medusa_direction)
{
    static int counter;

    std::cout << "### DEBUG PRINT " << ++counter << " ###\n\n";

    
}

void DEBUG_vision_map()
{
    std::cin >> map_size;
    char map[50][50];

    pii medusa_pos;
    std::set<pii> warriors_pos;

    for (int y = 0; y < map_size; y++)
    {
        for (int x = 0; x < map_size; x++)
        {
            char c;
            std::cin >> c;

            if (c == 'm')
                medusa_pos = {y, x};
            else if (c == 'w')
            {
                warriors_pos.insert({y, x});
                warrior_cnt[y][x]++;
            }

            map[y][x] = c;
        }
    }

    int d;
    std::cout << "Enter direction; 0 = up, 1 = down, 2 = left, 3 = right: ";
    std::cin >> d;

    update_vision_map(medusa_pos, warriors_pos, d);
    std::cout << '\n';
    // std::cout << count << " warriors counted.\n";
    std::cout << '\n';
    
    for (int y = 0; y < map_size; y++)
    {
        for (int x = 0; x < map_size; x++)
        {
            if (vision_map[d][y][x])
            {
                if (map[y][x] == 'w')
                    std::cout << '@';
                else
                    std::cout << '!';
            }
            else
            {
                std::cout << map[y][x];
            }
        }
        std::cout << '\n';
    }

    NL
}

int main()
{
    // std::ios::sync_with_stdio(0);
    // std::cin.tie(0), std::cout.tie(0);

    // DEBUG_vision_map();
    // return 0;

    char debug_map[50][50];

    int num_warrior_cnt;
    std::cin >> map_size >> num_warrior_cnt;
    
    for (int y = 0; y < map_size; y++)
    {
        for (int x = 0; x < map_size; x++)
            debug_map[y][x] = '.';
    }

    pii home_pos, dest_pos;
    std::cin >> home_pos.first >> home_pos.second;
    std::cin >> dest_pos.first >> dest_pos.second;

    debug_map[home_pos.first][home_pos.second] = 'M';
    debug_map[dest_pos.first][dest_pos.second] = 'D';

    std::set<pii> warriors_pos;

    for (int i = 0; i < num_warrior_cnt; i++)
    {
        int y, x;
        std::cin >> y >> x;
        warrior_cnt[y][x]++;
        warriors_pos.insert({y, x});

        debug_map[y][x] = 'W';
    }

    for (int y = 0; y < map_size; y++)
    {
        for (int x = 0; x < map_size; x++)
        {
            bool b;
            std::cin >> b;
            roads[y][x] = !b;
        }
    }

    NL
    for (int y = 0; y < map_size; y++)
    {
        for (int x = 0; x < map_size; x++)
            std::cout << debug_map[y][x];
        NL
    }
    NL

    std::vector<pii> medusa_path = get_path(home_pos, dest_pos);

    if (medusa_path.empty())
    {
        std::cout << -1;
        return 0;
    }

    for (int medusa_pos_idx = 1; medusa_pos_idx < medusa_path.size() - 1; medusa_pos_idx++)
    {
        int warrior_move_dist = 0;
        int num_petrified = 0;
        int num_attacks = 0;
        
        pii medusa_pos = medusa_path[medusa_pos_idx];

        for (int y = 0; y < map_size; y++)
        {
            for (int x = 0; x < map_size; x++)
                debug_map[y][x] = '.';
        }

        debug_map[medusa_pos.first][medusa_pos.second] = 'M';

        if (!warriors_pos.empty())
        {
            if (warriors_pos.find(medusa_pos) != warriors_pos.end())
            {
                std::cout << "Medusa kills warrior(s) on " << pii_to_str(medusa_pos); NL

                warriors_pos.erase(medusa_pos);
                warrior_cnt[medusa_pos.first][medusa_pos.second] = 0;
            }

            int medusa_direction;
            for (int direction = 0; direction < 4; direction++)
            {
                update_vision_map(medusa_pos, warriors_pos, direction);

                int count = 0;
                for (auto [y, x] : warriors_pos)
                {
                    if (vision_map[direction][y][x])
                        count += warrior_cnt[y][x];
                }

                if (count > num_petrified)
                {
                    num_petrified = count;
                    medusa_direction = direction;
                }
            }

            std::cout << "medusa looks " << dnames[medusa_direction] << ", petrifies " << num_petrified << ".\n";

            int new_warrior_cnt[50][50] = {0};

            std::set<pii> new_warriors_pos;

            for (pii warrior : warriors_pos)
            {
                int count = warrior_cnt[warrior.first][warrior.second];

                if (!vision_map[medusa_direction][warrior.first][warrior.second])
                {
                    pii new_pos = get_warrior_next_pos(
                        get_warrior_next_pos(warrior, medusa_pos, medusa_direction, 1),
                        medusa_pos, medusa_direction, 0
                    );

                    warrior_move_dist += count * get_distance(warrior, new_pos);

                    std::cout << count << " warrior(s) in " << pii_to_str(warrior); 

                    if (new_pos == medusa_pos)
                    {
                        std::cout << " attacks medusa.\n";
                        num_attacks += count;
                    }
                    else
                    {
                        std::cout << " moves to " << pii_to_str(new_pos) << '\n';
                        new_warriors_pos.insert(new_pos);
                        new_warrior_cnt[new_pos.first][new_pos.second] += count;

                        debug_map[new_pos.first][new_pos.second] = 'W';
                    }
                }
                else
                {
                    std::cout << "warrior at " << pii_to_str(warrior) << " is petrified\n";
                    new_warriors_pos.insert(warrior);
                    new_warrior_cnt[warrior.first][warrior.second] += count;

                    debug_map[warrior.first][warrior.second] = 'X';
                }
            }

            warriors_pos = new_warriors_pos;

            for (int y = 0; y < map_size; y++)
            {
                for (int x = 0; x < map_size; x++)
                {
                    // DONT DELETE THIS
                    warrior_cnt[y][x] = new_warrior_cnt[y][x];

                    std::cout << debug_map[y][x];
                }
                NL
            }
        }

        std::cout << warrior_move_dist << ' ' << num_petrified << ' ' << num_attacks << '\n';
    }

    std::cout << 0;
}