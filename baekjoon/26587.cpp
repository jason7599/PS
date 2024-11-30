#include <iostream>
#include <string>
#include <vector>
#include <set>

bool is_vowel_word(const std::string& word)
{
    static const std::set<char> VOWEL_SET =
    {
        'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'
    };

    return VOWEL_SET.count(word.front());
}

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

    while (!std::cin.eof())
    {
        std::string line;
        std::getline(std::cin, line);

        auto words = parse(line);

        std::vector<size_t> vowel_words_indices;

        for (size_t i = 0; i < words.size(); i++)
        {
            if (is_vowel_word(words[i]))
                vowel_words_indices.push_back(i);
        }

        for (size_t i = 0; i < vowel_words_indices.size() / 2; i++)
        {
            std::string vowel_word0 = words[vowel_words_indices[i]];
            std::string vowel_word1 = words[vowel_words_indices[vowel_words_indices.size() - 1 - i]];

            words[vowel_words_indices[i]] = vowel_word1;
            words[vowel_words_indices[vowel_words_indices.size() - 1 - i]] = vowel_word0;
        }

        for (const std::string& word : words)
            std::cout << word << ' ';
        std::cout << '\n';
    }
}