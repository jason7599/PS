#include <iostream>
#include <string>
#include <map>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    while (!std::cin.eof())
    {
        std::string lhs, rhs;
        getline(std::cin, lhs);
        getline(std::cin, rhs);

        std::map<char, int> lm, rm;
        for (char c : lhs) lm[c]++;
        for (char c : rhs) rm[c]++;

        for (const auto& [c, i] : lm)
        {
            if (rm.count(c))
                std::cout << std::string(std::min(i, rm.at(c)), c);
        }
        std::cout << '\n';
    }
}