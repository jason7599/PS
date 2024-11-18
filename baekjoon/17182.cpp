#include <iostream>
#include <algorithm>

int n_planets;
int dist_map[10][10];

void floyd_warshall()
{
    for (int k = 0; k < n_planets; k++)
    {
        for (int i = 0; i < n_planets; i++)
        {
            for (int j = 0; j < n_planets; j++)
                dist_map[i][j] = std::min(dist_map[i][j],
                    dist_map[i][k] + dist_map[k][j]);
        }
    }
}

int main()
{
    int start, perm[10], t;
    std::cin >> n_planets >> start;

    perm[0] = start;
    t = 1;

    for (int i = 0; i < n_planets; i++)
    {
        if (i != start)
            perm[t++] = i;

        for (int j = 0; j < n_planets; j++)
            std::cin >> dist_map[i][j];
    }

    floyd_warshall();

    int ans = 1e9;
    do
    {
        int res = 0;
        for (int i = 0; i < n_planets - 1; i++)
            res += dist_map[perm[i]][perm[i + 1]];

        ans = std::min(ans, res);

    } while (std::next_permutation(perm + 1, perm + n_planets));

    std::cout << ans;
}