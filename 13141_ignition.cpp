#include <iostream>
#include <algorithm>

const int inf = 2e9;

int n_nodes;
int dist_map[200][200];

void floyd_warshall()
{
    for (int k = 0; k < n_nodes; k++)
    {
        for (int i = 0; i < n_nodes; i++)
        {
            for (int j = 0; j < n_nodes; j++)
                dist_map[i][j] = std::min(dist_map[i][j],
                    dist_map[i][k] + dist_map[k][j]);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_edges;
    std::cin >> n_nodes >> n_edges;

    std::fill(&dist_map[0][0], &dist_map[n_nodes][0], inf);

    while (n_edges--)
    {
        int s, e, d;
        std::cin >> s >> e >> d;
        s--, e--;

        dist_map[s][e] = dist_map[e][s] = std::min(dist_map[s][e], d);
    }

    floyd_warshall();

    float min_time = inf;
    for (int start_node = 0; start_node < n_nodes; start_node++)
    {
        float time = 0;
        bool node_burnt[200] = {0};

        for (;; time++)
        {

        }

        min_time = std::min(min_time, time);
    }

    std::cout.precision(1);
    std::cout << std::fixed;

    std::cout << min_time;
}