#include <iostream>
#include <algorithm>

const int inf = 1e9;

int main()
{
    int n_people;
    int dist_map[50][50];
    
    std::cin >> n_people;

    for (int i = 0; i < n_people; i++)
    {
        for (int j = 0; j < n_people; j++)
        {
            char c;
            std::cin >> c;
            dist_map[i][j] = dist_map[j][i] =
                i == j ? 0 : 
                    c == 'Y' ? 1 : inf;
        }
    }

    for (int k = 0; k < n_people; k++)
    {
        for (int i = 0; i < n_people; i++)
        {
            for (int j = 0; j < n_people; j++)
                dist_map[i][j] = std::min(dist_map[i][j],
                    dist_map[i][k] + dist_map[k][j]);
        }
    }

    int max_friends = 0;
    for (int i = 0; i < n_people; i++)
    {
        int friends = 0;
        for (int j = 0; j < n_people; j++)
        {
            if (i != j && dist_map[i][j] <= 2)
                max_friends = std::max(max_friends, ++friends);
        }
    }

    std::cout << max_friends;
}