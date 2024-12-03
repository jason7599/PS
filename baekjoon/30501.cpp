#include <iostream>
#include <string>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_suspects;
    std::cin >> n_suspects;

    while (n_suspects--)
    {
        std::string name;
        std::cin >> name;

        if (name.find('S') != std::string::npos)
        {
            std::cout << name;
            std::exit(0);
        }
    }
}