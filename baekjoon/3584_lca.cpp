#include <iostream>
#include <vector>
#include <set>

std::vector<int> tree[10'001];

int find_lca(int root, int p, int q)
{
    if (root == p || root == q)
        return root;
    
    int lca = 0;

    for (int child : tree[root])
    {
        int t = find_lca(child, p, q);
        if (t)
        {
            if (lca)
                return root;
            lca = t;
        }
    }

    return lca;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_tc;
    std::cin >> n_tc;

    while (n_tc--)
    {
        int n_nodes;
        std::cin >> n_nodes;

        std::set<int> root_set;
        for (int n = 1; n <= n_nodes; n++)
        {
            tree[n].clear();
            root_set.insert(n);
        }

        for (int i = 0; i < n_nodes - 1; i++)
        {
            int parent, child;
            std::cin >> parent >> child;

            tree[parent].push_back(child);
            root_set.erase(child);
        }

        int p, q;
        std::cin >> p >> q;
        std::cout << find_lca(*root_set.begin(), p, q) << '\n';
    }
}