#include <bits/stdc++.h>

struct Flight
{
    int dest;
    int meal_val;
};

int max_meal_val(const std::vector<std::vector<Flight>>& connections, int city_idx, int n_stops)
{
    static int memo[300][301];

    if (city_idx == connections.size() - 1)
        return 0;
    
    if (!--n_stops)
        return -1;

    int& res = memo[city_idx][n_stops];
    if (res)
        return res;

    res = -1;
    for (const Flight& flight : connections[city_idx])
    {
        int t = max_meal_val(connections, flight.dest, n_stops);
        if (t != -1)
            res = std::max(res, flight.meal_val + t);
    }

    return res;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_cities, n_stops, n_flights;
    std::cin >> n_cities >> n_stops >> n_flights;

    std::vector<std::vector<Flight>> connections(n_cities);

    for (int i = 0; i < n_flights; i++)
    {
        int from, to, meal_val;
        std::cin >> from >> to >> meal_val;
        
        if (from < to)
        {
            from--, to--;
            connections[from].push_back(Flight{to, meal_val});
        }
    }

    std::cout << max_meal_val(connections, 0, n_stops) << '\n';
}