#include <iostream>
#include <vector>
#include <algorithm>

struct Node
{
    std::vector<int> adj_list;
    int parent;
    int size; // size of subtree
};

int n_nodes;
Node tree[10'001];

void dfs(int node, int parent)
{
    tree[node].parent = parent;

    int size = 1;

    for (int adj : tree[node].adj_list)
    {
        if (adj != parent)
        {
            dfs(adj, node);
            size += tree[adj].size;
        }
    }

    tree[node].size = size;
}

bool node_compare_by_size(const int& lhs, const int& rhs)
{
    return tree[lhs].size < tree[rhs].size;
}

void prune(std::vector<int>& level, int max_width)
{
    std::vector<int> nlevel;
    for (int node : level)
    {
        for (int adj : tree[node].adj_list)
        {
            if (adj != tree[node].parent)
                nlevel.push_back(adj);
        }
    }

    if (!nlevel.empty())
        prune(nlevel, max_width);

    // std::cout << '{';
    // for (int i : level)
    //     std::cout << i << ' ';
    // std::cout << "}\n";

    if (level.size() > max_width)
    {
        // std::cout << "pruning!\n";

        std::sort(level.begin(), level.end(), node_compare_by_size);

        int n_prune = level.size() - max_width;

        for (int i = 0; i < n_prune; i++)
        {
            // std::cout << "removing " << level[i] << ", size = " << tree[level[i]].size << '\n';

            const Node& node = tree[level[i]];
            
            n_nodes -= node.size;
            tree[node.parent].size -= node.size;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int max_width;
    std::cin >> n_nodes >> max_width;
    for (int i = 0; i < n_nodes - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        tree[u].adj_list.push_back(v);
        tree[v].adj_list.push_back(u);
    }

    dfs(1, 0);

    prune(tree[1].adj_list, max_width);
    
    std::cout << n_nodes << '\n';
}