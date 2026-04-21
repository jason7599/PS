#include <iostream>
#include <algorithm>

const int max_nodes = 100;
const int inf = 1e9;

int num_nodes;
int item_vals[max_nodes];
int dist_map[max_nodes][max_nodes];

void floyd()
{
    for (int k = 0; k < num_nodes; k++)     // "middleman" node
    {
        for (int i = 0; i < num_nodes; i++) // start node
        {
            for (int j = 0; j < num_nodes; j++) // end node
                dist_map[i][j] = std::min(dist_map[i][j],
                    dist_map[i][k] + dist_map[k][j]);
        }
    }
}

int search_items(int node, int search_dist)
{
    int res = 0;
    for (int other = 0; other < num_nodes; other++)
    {
        if (search_dist >= dist_map[node][other])
            res += item_vals[other];
    }
    return res;
}

int main()
{
    int search_dist, num_edges;
    std::cin >> num_nodes >> search_dist >> num_edges;

    std::fill(&dist_map[0][0], &dist_map[num_nodes][0], inf);

    for (int i = 0; i < num_nodes; i++)
    {
        std::cin >> item_vals[i];
        dist_map[i][i] = 0;
    }

    for (int i = 0; i < num_edges; i++)
    {
        int a, b, dist;
        std::cin >> a >> b >> dist;
        a--, b--;

        dist_map[a][b] = dist_map[b][a] = dist;
    }

    int ans = 0;
    for (int i = 0; i < num_nodes; i++)
        ans = std::max(ans, search_items(i, search_dist));
    
    std::cout << ans;
}