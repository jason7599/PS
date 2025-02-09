#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_stations;
    std::cin >> n_stations;

    std::vector<int> road_len(n_stations - 1);
    std::vector<int> gas_prices(n_stations);

    for (int& len : road_len)
        std::cin >> len;
    
    for (int& price : gas_prices)
        std::cin >> price;
    
    int64_t total_cost = 0;
    int min_price = 1e9;

    for (size_t i = 0; i < n_stations - 1; i++)
    {
        min_price = std::min(min_price, gas_prices[i]);
        total_cost += static_cast<int64_t>(min_price) * road_len[i];
    }

    std::cout << total_cost << '\n';
}