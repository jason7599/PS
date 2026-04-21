#include <iostream>
#include <algorithm>

const int inf = 1e9;

int n_nodes;
int dist[100][100];

void floyd()
{
    for (int k = 0; k < n_nodes; k++)
    {
        for (int i = 0; i < n_nodes; i++)
        {
            for (int j = 0; j < n_nodes; j++)
                dist[i][j] = std::min(dist[i][j],
                    dist[i][k] + dist[k][j]);
        }
    }
}

int main()
{
    int n_edges;
    std::cin >> n_nodes;

    std::fill(&dist[0][0], &dist[n_nodes][0], inf);

    std::cin >> n_edges;
    while (n_edges--)
    {
        int a, b, d;
        std::cin >> a >> b >> d;
        a--, b--;
        
        dist[a][b] = std::min(dist[a][b], d);
    }

    floyd();

    for (int i = 0; i < n_nodes; i++)
    {
        for (int j = 0; j < n_nodes; j++)
            std::cout << (i == j || dist[i][j] == inf ? 0 : dist[i][j]) << ' ';
        std::cout << '\n';
    }
}