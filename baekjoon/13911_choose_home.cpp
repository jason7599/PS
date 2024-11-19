#include <iostream>
#include <algorithm>
#include <queue>

constexpr int max_nodes = 10'000;
constexpr int inf = 1e9;

static constexpr short t_mcd = 0;
static constexpr short t_stb = 1;

struct Edge
{
    int to;
    int dist;

    Edge(){}
    Edge(int t, int d) : to(t), dist(d) {}
};

struct EdgeCompare
{
    bool operator()(const Edge& lhs, const Edge& rhs)
    {
        return lhs.dist > rhs.dist;
    }
};

struct Node
{
    bool is_home = 1;
    std::vector<Edge> edges;
};

int n_nodes;
Node nodes[max_nodes];
int dist_map[max_nodes][2];

void djikstra(
    std::priority_queue<Edge, std::vector<Edge>, EdgeCompare>& pq, 
    short t)
{
    while (!pq.empty())
    {
        const auto [node, cur_dist] = pq.top();
        pq.pop();

        if (cur_dist > dist_map[node][t])
            continue;
        
        for (const auto [nbor, weight] : nodes[node].edges)
        {
            int ndist = cur_dist + weight;
            if (ndist < dist_map[nbor][t])
            {
                dist_map[nbor][t] = ndist;
                pq.push(Edge(nbor, ndist));
            }
        }
    }
}

int main()
{
    int n_edges;
    std::cin >> n_nodes >> n_edges;

    std::fill(&dist_map[0][0], &dist_map[n_nodes][0], inf);

    while (n_edges--)
    {
        int a, b, d;
        std::cin >> a >> b >> d;
        a--, b--;

        nodes[a].edges.push_back(Edge(b, d));
        nodes[b].edges.push_back(Edge(a, d));
    }
    
    int ent_range[2];
    for (short t = t_mcd; t <= t_stb; t++)
    {
        int n_ent;
        std::cin >> n_ent >> ent_range[t];

        std::priority_queue<Edge, std::vector<Edge>, EdgeCompare> pq;
        while (n_ent--)
        {
            int ent;
            std::cin >> ent;
            ent--;

            nodes[ent].is_home = 0;
            pq.push(Edge(ent, 0));
        }

        djikstra(pq, t);
    }

    int min_dists = inf;
    for (int n = 0; n < n_nodes; n++)
    {
        if (nodes[n].is_home)
        {
            if (dist_map[n][t_mcd] <= ent_range[t_mcd]
                && dist_map[n][t_stb] <= ent_range[t_stb])
            {
                int dists = dist_map[n][t_mcd] + dist_map[n][t_stb];
                min_dists = std::min(min_dists, dists);
            }
        }
    }

    std::cout << (min_dists == inf ? -1 : min_dists);
}