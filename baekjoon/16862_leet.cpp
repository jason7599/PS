#include <iostream>
#include <string>
#include <map>

const std::map<std::string, char> abbrs =
{
    {"at", '@'},
    {"and", '&'},
    {"one", '1'},
    {"won", '1'},
    {"to", '2'},
    {"too", '2'},
    {"two", '2'},
    {"for", '4'},
    {"four", '4'},
    {"bea", 'b'},
    {"be", 'b'},
    {"bee", 'b'},
    {"sea", 'c'},
    {"see", 'c'},
    {"eye", 'i'},
    {"oh", 'o'},
    {"owe", 'o'},
    {"are", 'r'},
    {"you", 'u'},
    {"why", 'y'}
};

inline bool is_upper(char c)
{
    return 'A' <= c && c <= 'Z';
}

inline bool is_alpha(char c)
{
    return is_upper(c) || ('a' <= c && c <= 'z');
}

inline char to_upper(char c)
{
    return c - 'a' + 'A';
}

inline char to_lower(char c)
{
    return c - 'A' + 'a';
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int num_lines;
    std::cin >> num_lines;
    std::cin.ignore();

    while (num_lines--)
    {
        std::string line;
        std::getline(std::cin, line);

        size_t i = 0;
        while (i < line.length())
        {
            char c = line[i];
            
            if (!is_alpha(c))
            {
                std::cout << c;
                i++;
                continue;
            }
            
            bool upper = is_upper(c);
            if (upper)
                c = line[i] = to_lower(line[i]);

            char res = c;
            size_t match = 1;
            for (const auto& [str, ch] : abbrs)
            {
                if (i + str.length() <= line.length())
                {
                    if (line.substr(i, str.length()) == str)
                    {
                        if (match < str.length())
                        {
                            match = str.length();
                            res = ch;
                        }
                    }
                }
            }

            if (upper && is_alpha(res))
                res = to_upper(res);

            std::cout << res;
            i += match;
        }
        std::cout << '\n';
    }
}