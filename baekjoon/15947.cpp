#include <iostream>
#include <string>
#include <vector>

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

const std::vector<std::string> lyrics = parse("baby sukhwan tururu turu very cute tururu turu in bed tururu turu baby sukhwan");

int main()
{
    int word_num;
    std::cin >> word_num;

    int word_idx = (word_num - 1) % lyrics.size();
    int iter = (word_num - 1) / lyrics.size();

    auto word = lyrics.at(word_idx);

    if (!iter || word.front() != 't')
        std::cout << word;
    else
    {
        int ru_cnt = (word.length() - 2) / 2 + iter;
        if (ru_cnt < 5)
        {
            std::cout << "tu";
            while (ru_cnt--)
                std::cout << "ru";
        }
        else
            std::cout << "tu+ru*" << ru_cnt; 
    }
}