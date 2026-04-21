#include <iostream>
#include <vector>
#include <algorithm>

struct Town
{
    int location;
    int population;
};

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_towns;
    std::cin >> n_towns;

    std::vector<Town> towns(n_towns);

    for (Town& town : towns)
        std::cin >> town.location >> town.population;
    
    std::sort(towns.begin(), towns.end(), [](const Town& lhs, const Town& rhs)
    {
        return lhs.location < rhs.location;
    });

    std::vector<int64_t> pop_sum(n_towns);
    std::vector<int64_t> pop_loc_mult_sum(n_towns);

    pop_sum[0] = towns[0].population;
    pop_loc_mult_sum[0] = towns[0].population * towns[0].location;

    for (size_t i = 1; i < n_towns; i++)
    {
        pop_sum[i] = pop_sum[i - 1] + towns[i].population;
        pop_loc_mult_sum[i] = pop_loc_mult_sum[i - 1] + towns[i].population * towns[i].location;
    }

    int best_location;
    int64_t min_dist = INT64_MAX;
    size_t k = 0;

    for (int location = towns.front().location; location <= towns.back().location; location++)
    {
        if ()
    }
}