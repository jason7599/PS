#include <iostream>
#include <string>
#include <vector>
#include <set>

std::vector<std::string> parse(const std::string& line)
{
    std::vector<std::string> res;

    size_t pos = 0;
    size_t t;
    while ((t = line.find(' ', pos)) != std::string::npos)
    {
        res.push_back(line.substr(pos, t - pos));
        pos = t + 1;
    }
    res.push_back(line.substr(pos));

    return res;
}

int main()
{
    std::string line;
    std::getline(std::cin, line);

    auto parsed = parse(line);
    std::set<std::string> set;

    bool repeat = 0;
    for (const auto& word : parsed)
    {
        if (set.find(word) == set.end())
            set.insert(word);
        else
        {
            repeat = 1;
            break;
        }
    }

    std::cout << (repeat ? "no" : "yes");
}