#include <iostream>
#include <algorithm>
#include <queue>

constexpr char c_dr = '\\';
constexpr char c_ur = '/';

constexpr int inf = 1e9;

struct Edge
{
    std::pair<int, int> to;
    int dist;

    Edge(){}
    Edge(std::pair<int, int> t, int d) : to(t), dist(d) {}
};

struct EdgeCompare
{
    bool operator()(const Edge& lhs, const Edge& rhs)
    {
        return lhs.dist > rhs.dist;
    }
};

int b_height, b_width;
char board[501][501];
int dist_map[501][501];
std::vector<Edge> edges[501][501];

void dijkstra()
{
    std::priority_queue<Edge, std::vector<Edge>, EdgeCompare> pq;
    pq.push(Edge({1, 1}, 0));

    while (!pq.empty())
    {
        const auto [pos, cur_dist] = pq.top();
        pq.pop();

        if (dist_map[pos.first][pos.second] < cur_dist)
            continue;
        
        for (const auto [npos, dist] : edges[pos.first][pos.second])
        {
            if ((npos.first < 0 || npos.second < 0)
                || ((npos.first != b_height || npos.second != b_width)
                    && (npos.first >= b_height || npos.second >= b_width)))
                continue;

            int ndist = cur_dist + dist;
            if (ndist < dist_map[npos.first][npos.second])
            {
                dist_map[npos.first][npos.second] = ndist;
                pq.push(Edge(npos, ndist));
            }
        }
    }
}

int main()
{
    std::cin >> b_height >> b_width;

    for (int y = 0; y < b_height; y++)
    {
        for (int x = 0; x < b_width; x++)
        {
            dist_map[y][x] = inf;

            std::cin >> board[y][x];
            if (board[y][x] == c_dr)
            {
                edges[y][x].push_back(Edge({y + 1, x + 1}, 0));
                edges[y + 1][x + 1].push_back(Edge({y, x}, 0));
                
                edges[y + 1][x].push_back(Edge({y, x + 1}, 1));
                edges[y][x + 1].push_back(Edge({y + 1, x}, 1));
            }
            else // ur
            {
                edges[y + 1][x].push_back(Edge({y, x + 1}, 0));
                edges[y][x + 1].push_back(Edge({y + 1, x}, 0));

                edges[y][x].push_back(Edge({y + 1, x + 1}, 1));
                edges[y + 1][x + 1].push_back(Edge({y, x}, 1));
            }
        }
    }

    std::fill(&dist_map[b_height][0], &dist_map[b_height][b_width], inf);

    dijkstra();

    for (int y = 0; y < b_height + 1; y++)
    {
        for (int x = 0; x < b_width + 1; x++)
        {
            if (dist_map[y][x] == inf)
                std::cout << "-";
            else
                std::cout << dist_map[y][x];
        }
        std::cout << '\n';
    }

    if (dist_map[b_height][b_width] == inf)
        std::cout << "NO SOLUTION";
    else
        std::cout << dist_map[b_height][b_width];
}
