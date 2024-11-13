#include <iostream>
#include <algorithm>

struct Item
{
    int weight;
    int value;
};

int num_items;
Item items[100];

int get_max_value(int item_idx, int max_weight)
{
    static int memo[100][100'001];

    if (item_idx == num_items || !max_weight)
        return 0;

    if (memo[item_idx][max_weight])
        return std::max(memo[item_idx][max_weight], 0);

    int res = get_max_value(item_idx + 1, max_weight);

    if (max_weight >= items[item_idx].weight)
    {
        res = std::max(res, items[item_idx].value 
            + get_max_value(item_idx + 1, max_weight - items[item_idx].weight));
    }

    memo[item_idx][max_weight] = res ? res : -1;
    return res;
}

int main()
{
    int max_weight;
    std::cin >> num_items >> max_weight;
    for (int i = 0; i < num_items; i++)
        std::cin >> items[i].weight >> items[i].value;

    std::cout << get_max_value(0, max_weight);
}