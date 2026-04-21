#include <iostream>
#include <algorithm>

const int MAX_N_PEOPLE = 1000;

struct Demand
{
    int min;
    int max;
};

Demand demands[MAX_N_PEOPLE];

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_people, total_val;
    std::cin >> n_people >> total_val;

    int min_demand_sum = 0;
    int max_demand_sum = 0;
    
    // denotes the maximum value among the min_demands and max_demands
    // use as lowerbound and upperbound for bsearching
    int l_bound = 0;
    int u_bound = 0;
    
    for (int i = 0; i < n_people; i++)
    {
        int min, max;
        std::cin >> min >> max;

        demands[i].min = min;
        demands[i].max = max;

        min_demand_sum += min;
        max_demand_sum += max;

        l_bound = std::max(l_bound, min);
        u_bound = std::max(u_bound, max);
    }

    //  1. impossible to even fulfil the min demand
    //  2. total_val greater than max demand, resulting in leftovers
    if (min_demand_sum > total_val
    || max_demand_sum < total_val)
    {
        std::cout << -1;
        return 0;
    }

    while (l_bound <= u_bound)
    {
        int val = (l_bound + u_bound) / 2; //

        int sum = 0;
        for (int i = 0; i < n_people; i++)
            sum += std::min(val, demands[i].max);

        if (sum >= total_val) 
            u_bound = val - 1;
        else
            l_bound = val + 1;
    }

    std::cout << l_bound;
}