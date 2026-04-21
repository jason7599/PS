#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

const std::unordered_set<std::string> IGNORE = 
{
    "i", "pa", "te", "ni", "niti", "a", "ali", "nego", "no", "ili"
};

std::vector<std::string> parse(const std::string& line)
{
    std::vector<std::string> parsed;

    size_t base = 0;
    size_t t;
    while ((t = line.find(' ', base)) != std::string::npos)
    {
        parsed.push_back(line.substr(base, t - base));
        base = t + 1;
    }
    parsed.push_back(line.substr(base));

    return parsed;
}

inline char to_upper(char lower)
{
    return lower - 'a' + 'A';
}

int main()
{
    std::string line;
    std::getline(std::cin, line);

    auto parsed = parse(line);

    std::cout << to_upper(parsed[0][0]);

    for (size_t i = 1; i < parsed.size(); i++)
    {
        const std::string& word = parsed.at(i);

        if (IGNORE.count(word))
            continue;
        
        std::cout << to_upper(word[0]);
    }

    std::cout << '\n';
}