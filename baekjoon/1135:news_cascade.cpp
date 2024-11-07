#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> tree[50];

int solve(int idx)
{
    int res = 0;
    for (int child : tree[idx])
    {
        res += 1 + solve(child);
    }
    return res;
}

int main()
{
    int num_nodes;
    std::cin >> num_nodes;
    
    for (int i = 0; i < num_nodes; i++)
    {
        int parent;
        std::cin >> parent;
        if (i) tree[parent].push_back(i);
    }

    std::cout << solve(0);
}