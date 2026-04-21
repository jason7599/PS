#include <bits/stdc++.h>

/**
 * for each turn:
 * 1. find mst cost. 0 if impossible
 * 2. remove the smallest weighted edge in mst
 *
 */

struct Edge
{
    int node0;
    int node1;
};

int find_root(std::vector<int> &roots, int node)
{
    if (roots[node] != node)
        roots[node] = find_root(roots, roots[node]);
    return roots[node];
}

int mst_cost(int n_nodes, const std::vector<Edge> &edges, size_t start_edge_idx)
{
    std::vector<int> roots(n_nodes);
    for (int i = 0; i < n_nodes; i++)
        roots[i] = i;

    int cost = 0;
    int n_conns = 0;

    for (size_t edge_idx = start_edge_idx; edge_idx < edges.size(); edge_idx++)
    {
        const Edge &edge = edges[edge_idx];

        int root0 = find_root(roots, edge.node0 - 1);
        int root1 = find_root(roots, edge.node1 - 1);

        if (root0 != root1)
        {
            if (root0 < root1)
                roots[root1] = root0;
            else
                roots[root0] = root1;

            cost += edge_idx + 1;

            if (++n_conns == n_nodes - 1)
                return cost;
        }
    }

    return -1;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_nodes, n_edges, n_turns;
    std::cin >> n_nodes >> n_edges >> n_turns;

    std::vector<Edge> edges(n_edges);

    for (Edge &edge : edges)
        std::cin >> edge.node0 >> edge.node1;

    int turn = 0;
    for (; turn < n_turns; turn++)
    {
        int cost = mst_cost(n_nodes, edges, turn);
        if (cost == -1)
            break;
        std::cout << cost << ' ';
    }

    for (; turn < n_turns; turn++)
        std::cout << 0 << ' ';

    std::cout << '\n';
}