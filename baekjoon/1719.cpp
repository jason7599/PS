#include <iostream>
#include <algorithm>

const int inf = 1e9;

int n_nodes;
int dist_map[200][200];
int next_node[200][200];

void floyd_warshall()
{
    for (int k = 0; k < n_nodes; k++)
    {
        for (int i = 0; i < n_nodes; i++)
        {
            for (int j = 0; j < n_nodes; j++)
            {
                int nd = dist_map[i][k] + dist_map[k][j];
                if (nd < dist_map[i][j])
                {
                    dist_map[i][j] = nd;
                    next_node[i][j] = next_node[i][k];
                }
            }
        }
    }
}

int main()
{
    int n_edges;
    std::cin >> n_nodes >> n_edges;

    std::fill(&dist_map[0][0], &dist_map[n_nodes][0], inf);

    while (n_edges--)
    {
        int a, b, d;
        std::cin >> a >> b >> d;
        a--, b--;

        dist_map[a][b] = dist_map[b][a] = d;
        next_node[a][b] = b;
        next_node[b][a] = a;
    }

    floyd_warshall();

    for (int i = 0; i < n_nodes; i++)
    {
        for (int j = 0; j < n_nodes; j++)
        {
            if (i == j) std::cout << "- ";
            else std::cout << next_node[i][j] + 1 << ' ';
        }
        std::cout << '\n';
    }
}