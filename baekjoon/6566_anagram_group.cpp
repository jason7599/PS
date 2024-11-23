#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::map<std::string, std::vector<std::string>> groups;

    while (!std::cin.eof())
    {
        std::string word;
        std::cin >> word;

        if (word.empty())
            break;

        std::string repr = word;
        std::sort(repr.begin(), repr.end());

        if (groups.find(repr) == groups.end())
            groups[repr] = {word};
        else
            groups[repr].push_back(word);
    }

    std::vector<std::vector<std::string>> res;
    for (auto& [repr, words] : groups)
    {
        std::sort(words.begin(), words.end());
        res.push_back(words);
    }

    std::sort(res.begin(), res.end(), 
        [](const std::vector<std::string>& lhs, const std::vector<std::string>& rhs)
        {
            if (lhs.size() == rhs.size())
                return lhs.front() < rhs.front();
            return lhs.size() > rhs.size();
        }
    );

    for (int i = 0; i < std::min(5, (int)res.size()); i++)
    {
        const auto& words = res.at(i);
        std::cout << "Group of size " << words.size() << ": ";
        std::string prev;
        for (const std::string& word : words)
        {
            if (prev != word)
            {
                std::cout << word << ' ';
                prev = word;
            }
        }
        std::cout << ".\n";
    }
}