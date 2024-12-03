#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::string longest_word;

    while (1)
    {
        std::string line;
        std::getline(std::cin, line);

        std::string word;

        for (char c : line)
        {
            if (('a' <= c && c <= 'z')
            || ('A' <= c && c <= 'Z')
            || c == '-')
                word += c;
            else
            {
                if (word.length() > longest_word.length())
                    longest_word = word;

                word.clear();
            }
        }

        if (word == "E-N-D")
            break;

        if (word.length() > longest_word.length())
            longest_word = word;
    }
    
    for (char c : longest_word)
    {
        if ('A' <= c && c <= 'Z')
            std::cout << (char)(c - 'A' + 'a');
        else
            std::cout << c;
    }
}