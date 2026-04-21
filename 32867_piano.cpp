#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_keys, width;
    std::cin >> n_keys >> width;

    std::vector<int> keys(n_keys);
    for (int& key : keys)
        std::cin >> key;
    
    int n_moves = 0;
    
    int cur_min = 2e6;
    int cur_max = 1;

    for (int key : keys)
    {
        cur_min = std::min(cur_min, key);
        cur_max = std::max(cur_max, key);

        if (cur_max - cur_min >= width)
        {
            n_moves++;
            cur_min = key;
            cur_max = key;
        }
    }

    std::cout << n_moves;
}