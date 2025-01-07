#include <bits/stdc++.h>

struct Edge
{
    int from;
    int to;
    int cost;
};

struct EdgeCmp
{
    bool operator()(const Edge& lhs, const Edge& rhs) const
    {
        return lhs.cost > rhs.cost;
    }
};

int roots[301];

int get_root(int node)
{
    if (roots[node] != node)
        roots[node] = get_root(roots[node]);
    return roots[node];
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_nodes;
    std::cin >> n_nodes;

    std::priority_queue<Edge, std::vector<Edge>, EdgeCmp> edges;

    for (int i = 1; i <= n_nodes; i++)
    {
        roots[i] = i;
    
        int b;
        std::cin >> b;

        edges.push(Edge{0, i, b});
    }

    for (int i = 1; i <= n_nodes; i++)
    {
        for (int j = 1; j <= n_nodes; j++)
        {
            int d;
            std::cin >> d;
            if (i < j)
                edges.push(Edge{i, j, d});
        }
    }

    int min_cost = 0;

    while (!edges.empty())
    {
        const auto [from, to, cost] = edges.top();
        edges.pop();

        int root0 = get_root(from);
        int root1 = get_root(to);

        if (root0 != root1)
        {
            min_cost += cost;

            if (root0 < root1)
                roots[root1] = root0;
            else
                roots[root0] = root1;
        }
    }

    std::cout << min_cost;
}