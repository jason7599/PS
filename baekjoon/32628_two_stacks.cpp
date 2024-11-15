#include <iostream>
#include <stack>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int bag_size, num_pops;
    std::cin >> bag_size >> num_pops;

    std::stack<int> bag[2];
    long long weight[2] = {0};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < bag_size; j++)
        {
            int x;
            std::cin >> x;
            bag[i].push(x);
            weight[i] += x;
        }
    }

    while (num_pops--)
    {
        bool b = weight[0] < weight[1];
        weight[b] -= bag[b].top();
        bag[b].pop();
    }

    std::cout << std::max(weight[0], weight[1]);
}