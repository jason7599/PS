#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_tc;
    std::cin >> n_tc;

    while (n_tc--)
    {
        int n_cards;
        std::cin >> n_cards;
        
        std::string bobs;
        std::cin >> bobs;

        int upperbound = std::stoi(bobs);
        std::reverse(bobs.begin(), bobs.end());
        upperbound = std::min(upperbound, std::stoi(bobs));

        std::string alices;
        std::cin >> alices;

        
    }
}