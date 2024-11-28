#include <iostream>
#include <algorithm>

struct Node
{
    int val;
    int depth;
    int l_child = -1;
    int r_child = -1;
};

int n_nodes;
Node tree[200'001];

// returns 0 on fail
bool try_reconstruct()
{
    return 0;
}

void debug_print_nodes()
{
    for (int n = 1; n <= n_nodes; n++)
    {
        std::cout << "node " << n << ": val=" << tree[n].val << ", depth=" << tree[n].depth << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> n_nodes;
    for (int n = 1; n <= n_nodes; n++)
        std::cin >> tree[n].val >> tree[n].depth;
    
    std::sort(tree + 1, tree + 1 + n_nodes, 
        [](const Node& lhs, const Node& rhs)
        {
            if (lhs.depth == rhs.depth)
                return lhs.val < rhs.val;
            return lhs.depth < rhs.depth;
        }
    );


}