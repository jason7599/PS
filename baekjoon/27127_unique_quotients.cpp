#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;

    std::string str = "0123456789";
    int i = 0;

    do
    {
        std::string lhs = str.substr(0, 5);
        std::string rhs = str.substr(5);

        int l = std::stoi(lhs);
        int r = std::stoi(rhs);

        if (l % r == 0 && l / r == 9)
        {
            if (++i == n)
            {
                std::cout << lhs << ' ' << rhs;
                break;
            }
        }

    } while (std::next_permutation(str.begin(), str.end()));
    
}