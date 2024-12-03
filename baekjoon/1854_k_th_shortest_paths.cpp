#include <iostream>
#include <queue>
#include <algorithm>

const int MAX_NODES = 1e3;

struct Edge
{
    int to;
    int dist;

    bool operator<(const Edge& other) const
    {
        return dist > other.dist;
    }
};

struct Node
{
    std::vector<Edge> edges;
};

int n_nodes;
Node nodes[MAX_NODES + 1];

// std::priority_queue

int main()
{
    int n_edges, K;
    std::cin >> n_nodes >> n_edges >> K;

    while (n_edges--)
    {
        int from, to, dist;
        std::cin >> from >> to >> dist;
        nodes[from].edges.push_back({to, dist});
    }
}