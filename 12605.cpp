#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> parse(const std::string& line)
{
    std::vector<std::string> parsed;

    size_t pos = 0;
    size_t t;
    while ((t = line.find(' ', pos)) != std::string::npos)
    {
        parsed.push_back(line.substr(pos, t - pos));
        pos = t + 1;
    }
    parsed.push_back(line.substr(pos));

    return parsed;
}

int main()
{
    int n;
    std::cin >> n;
    std::cin.ignore();

    for (int i = 1; i <= n; i++)
    {
        std::string str;
        std::getline(std::cin, str);

        std::cout << "Case #" << i << ":";

        auto parsed = parse(str);
        for (auto ri = parsed.rbegin(); ri != parsed.rend(); ri++)
            std::cout << ' ' << *ri; 
        std::cout << '\n';
    }
}