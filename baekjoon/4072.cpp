#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> parse(const std::string& line)
{
    std::vector<std::string> parsed;
    size_t pos = 0;
    size_t next;
    while ((next = line.find(' ', pos)) != std::string::npos)
    {
        parsed.push_back(line.substr(pos, next - pos));
        pos = next + 1;
    }
    parsed.push_back(line.substr(pos));

    return parsed;
}

int main()
{
    while (1)
    {
        std::string line;
        std::getline(std::cin, line);

        if (line == "#")
            break;

        auto parsed = parse(line);
        for (const auto& word : parsed)
        {
            size_t j = word.length();
            while (j--)
                std::cout << word[j];
            std::cout << ' ';
        }
        std::cout << '\n';
    }
}