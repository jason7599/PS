#include <iostream>
#include <algorithm>
#include <unordered_set>

int main()
{
    int n_elems, elems[20];
    std::cin >> n_elems;

    for (int i = 0; i < n_elems; i++)
        std::cin >> elems[i];

    std::unordered_set<int> res;

    for (int mask = 1; mask < (1 << n_elems); mask++)
    {
        int sum = 0;
        for (int i = 0; i < n_elems; i++)
        {
            if (mask & (1 << i))
                sum += elems[i];
        }
        res.insert(sum);
    }

    int ans = 1;
    for (; res.count(ans); ans++);

    std::cout << ans;
}