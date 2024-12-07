#include <iostream>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_items;
    std::cin >> n_items;

    std::priority_queue<int> items;

    for (int i = 0; i < n_items; i++)
    {
        int item;
        std::cin >> item;
        items.push(item);
    }

    int res[2] = {};
    bool turn = 0;

    while (!items.empty())
    {
        res[turn] += items.top();
        items.pop();
        turn = !turn;
    }

    std::cout << res[0] << ' ' << res[1];
}