#include <iostream>
#include <string>
#include <algorithm>
#include <map>

const std::map<char, char> COUNTERS =
{
    {'R', 'S'},
    {'B', 'K'},
    {'L', 'H'},
};

int main()
{
    std::string str;
    std::cin >> str;

    size_t i = 0;
    while (i < str.length())
    {
        if (str.length() - i >= 3)
        {
            std::string tmp = str.substr(i, 3);
            if (tmp[0] != tmp[1] && tmp[1] != tmp[2] && tmp[0] != tmp[2])
            {
                std::cout << 'C';
                i += 3;
                continue;
            }
        }
        std::cout << COUNTERS.at(str[i]);
        i++;
    }
}