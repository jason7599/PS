#include <iostream>
#include <queue>
#include <algorithm>
#include <limits>

const int MAX_N_STATIONS = 2500;
const int MAX_PRICE = 2500;

const u_int64_t INF = std::numeric_limits<u_int64_t>::max();

struct Road
{
    int to;
    int dist;
};

struct Station
{
    int price;
    std::vector<Road> roads;
};

struct PQEntry
{
    int station;
    u_int64_t cur_cost;
    int min_price; // min price in path so far

    bool operator<(const PQEntry& other) const
    {
        if (cur_cost == other.cur_cost)
            return min_price > other.min_price;

        return cur_cost > other.cur_cost;
    }
};

int n_stations;
Station stations[MAX_N_STATIONS + 1];

u_int64_t dist_map[MAX_N_STATIONS + 1][MAX_PRICE + 1]; // [station][min_price]

u_int64_t solve()
{
    std::priority_queue<PQEntry> pq;
    pq.push({1, 0, stations[1].price});
    dist_map[1][stations[1].price] = 0;

    while (!pq.empty())
    {
        const auto [station, cur_cost, min_price] = pq.top();
        pq.pop();

        if (station == n_stations)
            return cur_cost;

        if (cur_cost > dist_map[station][min_price])
            continue;
        
        for (const auto [next, road_len] : stations[station].roads)
        {
            u_int64_t nx_cost = cur_cost + road_len * min_price;
            int nx_min_price = std::min(min_price, stations[next].price);

            if (nx_cost < dist_map[next][nx_min_price])
            {
                dist_map[next][nx_min_price] = nx_cost;
                pq.push({next, nx_cost, nx_min_price});
            }
        }
    }

    return 1 / 0;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_roads;
    std::cin >> n_stations >> n_roads;

    for (int i = 1; i <= n_stations; i++)
    {
        std::cin >> stations[i].price;
        std::fill(&dist_map[i][1], &dist_map[i][1 + MAX_PRICE], INF);
    }
    
    while (n_roads--)
    {
        int from, to, dist;
        std::cin >> from >> to >> dist;

        stations[from].roads.push_back({to, dist});
        stations[to].roads.push_back({from, dist});
    }

    std::cout << solve();
}