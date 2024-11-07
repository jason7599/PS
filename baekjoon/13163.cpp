#include <iostream>
#include <string>

int main()
{
    int t;
    std::cin >> t;
    std::cin.ignore();
    while (t--)
    {
        std::string line;
        std::getline(std::cin, line);

        std::cout << "god";
        for (size_t pos = line.find(' ') + 1; pos < line.length(); pos++)
        {
            if (line[pos] != ' ')
                std::cout << line[pos];
        }
        std::cout << '\n';
    }
}