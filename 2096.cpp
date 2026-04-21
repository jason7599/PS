#include <iostream>
#include <algorithm>

int main()
{
    int height;
    std::cin >> height;
    std::pair<int, int> arr[3];
    for (int i = 0; i < 3; i++)
    {
        int v;
        std::cin >> v;
        arr[i] = {v, v};
    }

    std::pair<int,int> tmp[3];
    for (int i = 1; i < height; i++)
    {
        for (int x = 0; x < 3; x++)
        {
            int t;
            std::cin >> t;

            int max = 0;
            int min = 1e9;
            for (int nx = std::max(x - 1, 0); nx <= std::min(x + 1, 2); nx++)
            {
                max = std::max(max, arr[nx].first);
                min = std::min(min, arr[nx].second);
            }
            tmp[x] = {max + t, min + t};
        }

        for (int j = 0; j < 3; j++)
            arr[j] = tmp[j];
    }

    auto [max, min] = arr[0];
    for (int i = 1; i < 3; i++)
    {
        max = std::max(max, arr[i].first);
        min = std::min(min, arr[i].second);
    }

    std::cout << max << ' ' << min;
}