#include <iostream>
#include <vector>
#include <algorithm>

constexpr int log2(int n)
{
    int res = 0;
    while (n >>= 1)
        res++;
    return res;
}

const int MAX_NODES = 50'000;
const int LOG = log2(MAX_NODES) + 1;

std::vector<int> adj_map[MAX_NODES + 1];
int jump_table[MAX_NODES + 1][LOG];
int depth[MAX_NODES + 1];

void dfs(int node, int parent)
{
    jump_table[node][0] = parent;
    depth[node] = parent == -1 ? 0 : depth[parent] + 1;

    for (int i = 1; i < LOG; i++)
    {
        if (jump_table[node][i - 1] != -1)
            jump_table[node][i] = jump_table[jump_table[node][i - 1]][i - 1];
        else
            jump_table[node][i] = -1;
    }

    for (int child : adj_map[node])
    {
        if (child != parent)
            dfs(child, node);
    }
}

int find_lca(int u, int v)
{
    if (depth[u] < depth[v])
    {
        int t = u;
        u = v;
        v = t;
    }

    for (int i = LOG - 1; i >= 0; i--)
    {
        if (depth[u] - (1 << i) >= depth[v])
            u = jump_table[u][i];
    }

    if (u == v)
        return u;
    
    for (int i = LOG - 1; i >= 0; i--)
    {
        if (jump_table[u][i] != jump_table[v][i])
        {
            u = jump_table[u][i];
            v = jump_table[v][i];
        }
    }

    return jump_table[u][0];
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_nodes;
    std::cin >> n_nodes;

    std::fill(&jump_table[0][0], &jump_table[n_nodes + 1][0], -1);

    for (int i = 0; i < n_nodes - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj_map[u].push_back(v);
        adj_map[v].push_back(u);
    }

    dfs(1, -1);

    int n_queries;
    std::cin >> n_queries;

    while (n_queries--)
    {
        int u, v;
        std::cin >> u >> v;
        std::cout << find_lca(u, v) << '\n';
    }
}