#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        std::string word;
        std::cin >> word;

        std::string copy = word;
        
        std::cout << (std::next_permutation(copy.begin(), copy.end())
            ? copy : word) << '\n';
    }
}