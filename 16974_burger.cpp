#include <iostream>

int64_t count_all_patties_in_level(int level)
{
    return ((int64_t)1 << (level + 1)) - 1;
}

int64_t count_layers_in_level(int level)
{
    return 4 * ((int64_t)1 << level) - 3;
}

int64_t count_patties(int level, int64_t layer)
{
    /**
     * B L(n-1) P L(n-1) B
     */

    if (!--layer) // finishes with the first layer;  
        return level == 0;

    int64_t nx_layer_cnt = count_layers_in_level(level - 1);

    if (layer <= nx_layer_cnt) // finishes within the first L(n - 1)
        return count_patties(level - 1, layer);

    int64_t cnt = count_all_patties_in_level(level - 1); // consumes all the patties in first L(n - 1)
    layer -= nx_layer_cnt;

    cnt++;
    if (!--layer) // finishes with the patty
        return cnt;
    
    if (layer <= nx_layer_cnt) // finishes within the 2nd L(n - 1)
        return cnt + count_patties(level - 1, layer);
    
    return cnt + count_all_patties_in_level(level - 1);
}

int main()
{
    int level;
    int64_t layer; // max n_layers = 4 * 2^50 -3

    std::cin >> level >> layer;
    std::cout << count_patties(level, layer);
}