#include <iostream>
#include <queue>
#include <algorithm>

const int INF = 1e9;

const int MAX_N_NODES = 1000;

struct Edge
{
    int to;
    int dist;

    bool operator<(const Edge& other) const
    {
        return dist > other.dist;
    }
};

int n_nodes;
int dist_map[MAX_N_NODES + 1];
int path_prev[MAX_N_NODES + 1];
std::vector<Edge> edges[MAX_N_NODES + 1];

void dijkstra(int restrict0 = -1, int restrict1 = -1)
{
    std::fill(&dist_map[1], &dist_map[1 + n_nodes], INF);

    std::priority_queue<Edge> pq;
    pq.push({1, 0});
    dist_map[1] = 0;

    while (!pq.empty())
    {
        const auto [cur_node, cur_dist] = pq.top();
        pq.pop();

        if (cur_dist > dist_map[cur_node])
            continue;
        
        for (const auto [nx_node, dist] : edges[cur_node])
        {
            if ((cur_node == restrict0 && nx_node == restrict1)
            || (cur_node == restrict1 && nx_node == restrict0))
                continue;
            
            int nx_dist = cur_dist + dist;
            if (nx_dist < dist_map[nx_node])
            {
                dist_map[nx_node] = nx_dist;
                path_prev[nx_node] = cur_node;
                pq.push({nx_node, nx_dist});
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_edges;
    std::cin >> n_nodes >> n_edges;

    while (n_edges--)
    {
        int from, to, dist;
        std::cin >> from >> to >> dist;

        edges[from].push_back({to, dist});
        edges[to].push_back({from, dist});
    }

    dijkstra();

    std::vector<int> path;
    {
        int t = n_nodes;
        while (1)
        {
            path.push_back(t);
            if (t == 1)
                break;
            t = path_prev[t];
        }
    }

    int max_time = 0;
    for (size_t i = 0; i < path.size() - 1; i++)
    {
        dijkstra(path[i], path[i + 1]);
        max_time = std::max(max_time, dist_map[n_nodes]);
    }

    std::cout << max_time;
}