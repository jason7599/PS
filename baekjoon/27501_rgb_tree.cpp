#include <iostream>
#include <vector>
#include <algorithm>

const int max_nodes = 500'000;

struct Node
{
    int beauty[3];
    std::vector<int> adjlist;
};

int num_nodes;
Node tree[max_nodes + 1];
long long max_beauty[max_nodes + 1];
int max_beauty_c[max_nodes + 1];

long long get_max_beauty(int node, int color, int prev = 0)
{
    static long long memo[max_nodes + 1][3];

    if (memo[node][color])
        return memo[node][color];
    
    long long res = tree[node].beauty[color];

    for (int adj : tree[node].adjlist)
    {
        if (adj == prev)
            continue;

        long long t = 0;
        for (int c = 0; c < 3; c++)
        {
            if (c != color)
                t = std::max(t, get_max_beauty(adj, c, node));
        }
        res += t;
    }

    if (max_beauty[node] < res)
    {
        max_beauty[node] = res;
        max_beauty_c[node] = color;
    }

    return memo[node][color] = res;
}

int main()
{
    std::cin >> num_nodes;
    for (int i = 0; i < num_nodes - 1; i++)
    {
        int a, b;
        std::cin >> a >> b;
        tree[a].adjlist.push_back(b);
        tree[b].adjlist.push_back(a);
    }

    for (int i = 1; i <= num_nodes; i++)
    {
        for (int& b : tree[i].beauty)
            std::cin >> b;
    }

    long long ans = 0;
    for (int c = 0; c < 3; c++)
        ans = std::max(ans, get_max_beauty(1, c));

    const auto rgb = "RGB";

    std::cout << ans << '\n';
    for (int i = 1; i <= num_nodes; i++)
        std::cout << rgb[max_beauty_c[i]];
}