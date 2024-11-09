#include <iostream>
#include <vector>
#include <algorithm>

void print_vec(const std::vector<int>& vec)
{
    for (int i : vec)
        std::cout << i << ' ';
    std::cout << '\n';
}

void insert(std::vector<int>& vec, int val)
{
    size_t pos = std::upper_bound(vec.begin(), vec.end(), val) - vec.begin();
    vec.insert(vec.begin() + pos, val);
}

size_t find(const std::vector<int> vec, int val)
{
    return std::lower_bound(vec.begin(), vec.end(), val) - vec.begin();
}

int main()
{
    std::vector<int> vec;

    while (1)
    {
        int op, val;
        std::cin >> op >> val;
        if (op == 1)
        {
            insert(vec, val);
            print_vec(vec);
        }
        else if (op == 2)
        {
            std::cout << find(vec, val) << '\n';
        }
    }
}