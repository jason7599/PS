#include <iostream>
#include <algorithm>

int holes[500'000];

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int num_holes, volume;
    std::cin >> num_holes >> volume;

    for (int i = 0; i < num_holes; i++)
        std::cin >> holes[i];
    
    int max_blocked = 0;
    int blocked = 0;
    int l = 0;
    for (int r = 0; r < num_holes; r++)
    {
        blocked += holes[r];

        while (blocked > volume)
            blocked -= holes[l++];
        
        max_blocked = std::max(max_blocked, blocked);
    }

    std::cout << max_blocked;
}