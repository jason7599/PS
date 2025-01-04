#include <iostream>
#include <string>
#include <map>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int total_cnt = 0;
    std::map<std::string, int> species_freq;

    while (!std::cin.eof())
    {
        std::string species;
        std::getline(std::cin, species);

        if (species.empty())
            break;

        species_freq[species]++;
        total_cnt++;
    }

    std::cout.precision(4);
    std::cout << std::fixed;

    for (const auto& [species, freq] : species_freq)
        std::cout << species << ' ' << 100 * (double)freq / total_cnt << '\n';
}