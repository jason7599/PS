#include <iostream>
#include <queue>
#include <algorithm>

struct Station
{
    int location;
    int gas_amount;
};

int get_min_n_stops(const std::vector<Station>& stations, int dest_location, int init_gas)
{
    int gas_amount = init_gas;
    int n_stops = 0;
    
    std::priority_queue<int> gas_pq;

    int base = 0;
    
    for (const Station& station : stations)
    {
        if (station.location > base + gas_amount) // insufficient
        {
            base += gas_amount;
            gas_amount = 0;
            
            while (station.location > base + gas_amount)
            {
                if (gas_pq.empty())
                    return -1;
                
                gas_amount += gas_pq.top();
                gas_pq.pop();
                n_stops++;
            }
        }

        gas_pq.push(station.gas_amount);
    }

    while (base + gas_amount < dest_location)
    {
        if (gas_pq.empty())
            return -1;
        
        gas_amount += gas_pq.top();
        gas_pq.pop();
        n_stops++;
    }

    return n_stops;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_stations;
    std::cin >> n_stations;

    std::vector<Station> stations(n_stations);

    for (Station& station : stations)
        std::cin >> station.location >> station.gas_amount;

    std::sort(stations.begin(), stations.end(), [](const Station& lhs, const Station& rhs)
    {
        return lhs.location < rhs.location;   
    });

    int dest_location, init_gas;
    std::cin >> dest_location >> init_gas;

    std::cout << get_min_n_stops(stations, dest_location, init_gas) << '\n';
}