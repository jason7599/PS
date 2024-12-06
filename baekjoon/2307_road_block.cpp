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
std::vector<Edge> edges[MAX_N_NODES + 1];

int dist_map[MAX_N_NODES + 1];
int prevs[MAX_N_NODES + 1];

// todo: if tle or mle
void dijkstra(int start, int restrict0 = -1, int restrict1 = -1)
{
    std::priority_queue<Edge> pq;

    std::fill(&dist_map[1], &dist_map[1 + n_nodes], INF);

    dist_map[start] = 0;
    pq.push({start, 0});

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
                prevs[nx_node] = cur_node;
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

    const int START = 1;
    const int DEST = n_nodes;

    dijkstra(START, n_nodes);
    int og_dist = dist_map[DEST];

    std::vector<int> path;
    {
        int node = DEST;
        while (node) // sus
        {
            path.push_back(node);
            node = prevs[node];
        }
    } // reversed, but shouldn't matter

    int max_delay = 0;
    
    for (size_t path_idx = 0; path_idx + 1 < path.size(); path_idx++)
    {
        dijkstra(START, path[path_idx], path[path_idx + 1]);

        int new_dist = dist_map[DEST];
        if (new_dist == INF)
        {
            max_delay = -1;
            break;
        }

        int delay = new_dist - og_dist;
        max_delay = std::max(max_delay, delay);
    }

    std::cout << max_delay;
}