#include <iostream>
#include <algorithm>
#include <queue>

constexpr int inf = 1e9;

struct Edge
{
    int to;
    int dist;

    Edge() {}
    Edge(int t, int d) : to(t), dist(d) {}
};

struct EdgeCompare
{
    bool operator()(const Edge& lhs, const Edge& rhs)
    {
        return lhs.dist > rhs.dist;
    }
};

int n_nodes, dist_map[800];
std::vector<Edge> edges[800];

void dijkstra(int src)
{
    std::fill(dist_map, dist_map + n_nodes, inf);
    dist_map[src] = 0;

    std::priority_queue<Edge, std::vector<Edge>, EdgeCompare> pq;
    pq.push(Edge(src, 0));

    while (!pq.empty())
    {
        const auto [node, cur_dist] = pq.top();
        pq.pop();

        if (dist_map[node] < cur_dist)
            continue;

        for (const auto [nbor, weight] : edges[node])
        {
            int ndist = cur_dist + weight;
            if (ndist < dist_map[nbor])
            {
                dist_map[nbor] = ndist;
                pq.push(Edge(nbor, ndist));
            }
        } 
    }
}

int main()
{
    int n_edges;
    std::cin >> n_nodes >> n_edges;

    while (n_edges--)
    {
        int a, b, d;
        std::cin >> a >> b >> d;
        a--, b--;

        edges[a].push_back(Edge(b, d));
        edges[b].push_back(Edge(a, d));
    }

    int v0, v1;
    std::cin >> v0 >> v1;
    v0--, v1--;

    dijkstra(v0);

    int v0_src_dist = dist_map[0];
    int v0_dest_dist = dist_map[n_nodes - 1];
    int v0_v1_dist = dist_map[v1];

    if (v0_v1_dist == inf)
    {
        std::cout << -1;
        return 0;
    }

    dijkstra(v1);

    int v1_src_dist = dist_map[0];
    int v1_dest_dist = dist_map[n_nodes - 1];

    int res = inf;
    if (v0_src_dist != inf && v1_dest_dist != inf)
        res = v0_src_dist + v0_v1_dist + v1_dest_dist;
    if (v1_src_dist != inf && v0_dest_dist != inf)
        res = std::min(res, v1_src_dist + v0_v1_dist + v0_dest_dist);
    
    std::cout << (res == inf ? -1 : res);
}