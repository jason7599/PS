#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<size_t> cidcs[26];

int main()
{
    std::string abbr, src;
    std::cin >> abbr >> src;

    for (size_t i = 0; i < src.length(); i++)
        cidcs[src[i] - 'a'].push_back(i);

    int iter = 0;

    int rep = 1;
    size_t idx = 0; // within src
    for (char c : abbr)
    {
        const auto& idcs = cidcs[c - 'a'];

        if (idcs.empty())
        {
            rep = -1;
            break;
        }

        auto it = std::lower_bound(idcs.begin(), idcs.end(), idx);

        if (it == idcs.end())
        {
            it = std::lower_bound(idcs.begin(), idcs.end(), 0);
            rep++;
        }

        idx = *it + 1;
    }

    std::cout << rep;
}