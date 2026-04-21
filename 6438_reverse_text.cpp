#include <bits/stdc++.h>

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

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_lines;
    std::cin >> n_lines;
    std::cin.ignore();

    while (n_lines--)
    {
        std::string line;
        std::getline(std::cin, line);

        auto words = parse(line);

        for (int i = words.size() - 1; i >= 0; i--)
        {
            for (int j = words[i].length() - 1; j >= 0; j--)
                std::cout << words[i][j];
            std::cout << ' ';
        }
        std::cout << '\n';
    }
}