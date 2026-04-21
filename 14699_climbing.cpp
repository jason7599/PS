#include <bits/stdc++.h>

struct Node
{
    int height;
    std::vector<int> adjs;
};

int solve(const std::vector<Node>& nodes, int node_idx)
{
    static int cache[5000];

    int& res = cache[node_idx];
    
    if (res)
        return res;
    
    for (int adj : nodes[node_idx].adjs)
    {
        if (nodes[adj].height > nodes[node_idx].height)
            res = std::max(res, solve(nodes, adj));
    }

    return ++res;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_nodes, n_edges;
    std::cin >> n_nodes >> n_edges;

    std::vector<Node> nodes(n_nodes);

    for (int i = 0; i < n_nodes; i++)
        std::cin >> nodes[i].height;
    
    while (n_edges--)
    {
        int from, to;
        std::cin >> from >> to;
        
        from--, to--;

        nodes[from].adjs.push_back(to);
        nodes[to].adjs.push_back(from);
    }

    for (int i = 0; i < n_nodes; i++)
        std::cout << solve(nodes, i) << '\n';
}