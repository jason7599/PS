#include <iostream>
#include <queue>
#include <algorithm>

const int inf = 1e9;

struct Edge
{
    int to;
    int dist;
};

int n_nodes;
std::vector<Edge> edges[20'000];

int dist_map[20'000];

void dijkstra(int start)
{
    auto compare = [](const Edge& lhs, const Edge& rhs)
    {
        return lhs.dist > rhs.dist;
    };
    std::priority_queue<Edge, std::vector<Edge>, 
        decltype(compare)> pq(compare); 

    dist_map[start] = 0;
    pq.push(Edge{start, 0});

    while (!pq.empty())
    {
        auto [node, dist] = pq.top();
        pq.pop();

        for (const auto [next, edge_dist] : edges[node])
        {
            if (dist + edge_dist < dist_map[next])
            {
                dist_map[next] = dist + edge_dist;
                pq.push({next, dist_map[next]});
            }
        }
    }
}

int main()
{
    int n_edges;
    std::cin >> n_nodes >> n_edges;

    std::fill(dist_map, dist_map + n_nodes, inf);

    int start_node;
    std::cin >> start_node;
    start_node--;

    while (n_edges--)
    {
        int a, b, d;
        std::cin >> a >> b >> d;
        edges[a - 1].push_back(Edge{b - 1, d});
    }

    dijkstra(start_node);

    for (int n = 0; n < n_nodes; n++)
    {
        if (dist_map[n] == inf)
            std::cout << "INF";
        else
            std::cout << dist_map[n];
        std::cout << '\n';
    }
}