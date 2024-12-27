#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_stations;
    std::cin >> n_stations;

    std::vector<bool> is_transfer_station(n_stations);
    for (int i = 0; i < n_stations; i++)
    {
        bool x;
        std::cin >> x;
        is_transfer_station[i] = x;
    }

    bool win = 1;
    int i = n_stations - 2;
    while (i >= 0)
    {
        while (i >= 0 && !is_transfer_station[i])
            i--;
        
        if (!i)
            break;
        
        win = !win;
        if (!--i)
            break;
        
        win = !win;
        if (!--i)
            break;
    }

    std::cout << (win ? "mnx" : "alsdkffhgk");
}