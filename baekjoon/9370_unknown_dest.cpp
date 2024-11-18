#include <iostream>
#include <queue>
#include <algorithm>

const int inf = 1e9;

struct Edge
{
    int to, dist;

    Edge() {}
    Edge(int t, int d)
        : to(t), dist(d) {}
};

struct EdgeCompare
{
    bool operator()(const Edge& lhs, const Edge& rhs)
    {
        return lhs.dist > rhs.dist;
    }
};

int n_nodes;
int dist_map[2001];
std::vector<int> prev_nodes[2001];
std::vector<Edge> edges[2001];

void dijkstra(int start)
{
    std::fill(dist_map + 1, dist_map + 1 + n_nodes, inf);
    std::priority_queue<Edge, std::vector<Edge>, EdgeCompare> pq;

    pq.push(Edge(start, 0));
    dist_map[start] = 0;

    while (!pq.empty())
    {
        const auto edge = pq.top();
        pq.pop();

        if (edge.dist > dist_map[edge.to])
            continue;
        
        for (const auto other : edges[edge.to])
        {
            int dist = edge.dist + other.dist;
            if (dist < dist_map[other.to])
            {
                dist_map[other.to] = dist;
                prev_nodes[other.to] = {edge.to};
                pq.push(Edge(other.to, dist));

            }
            else if (dist == dist_map[other.to])
                prev_nodes[other.to].push_back(edge.to);
        }
    }
}

bool check_path_contains(int dest, int start, int node0, int node1)
{
    if (dest == start)
        return 0;

    if (dest == node0 || dest == node1)
    {
        int f = dest == node0 ? node1 : node0;
        for (int prev : prev_nodes[dest])
        {
            if (prev == f)
                return 1;
        }
        return 0;
    }

    for (int prev : prev_nodes[dest])
    {
        if (check_path_contains(prev, start, node0, node1))
            return 1;
    }

    return 0;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int t;
    std::cin >> t;

    while (t--)
    {
        int n_edges, n_dests;
        std::cin >> n_nodes >> n_edges >> n_dests;

        int start, node0, node1;
        std::cin >> start >> node0 >> node1;

        while (n_edges--)
        {
            int a, b, d;
            std::cin >> a >> b >> d;
            edges[a].push_back(Edge(b, d));
            edges[b].push_back(Edge(a, d));
        }

        dijkstra(start);

        std::vector<int> dests(n_dests);
        for (int i = 0; i < n_dests; i++)
            std::cin >> dests[i];
        
        std::sort(dests.begin(), dests.end());

        for (int dest : dests)
        {
            if (check_path_contains(dest, start, node0, node1))
                std::cout << dest << ' ';
        }
        std::cout << '\n';

        if (t)
        {
            for (int i = 1; i <= n_nodes; i++)
            {
                edges[i].clear();
                prev_nodes[i].clear();
            }
        }

    }
}