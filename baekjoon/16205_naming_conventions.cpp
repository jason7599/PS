#include <iostream>
#include <string>

const int NC_CAMEL = 0;
const int NC_SNAKE = 1;
const int NC_PASCAL = 2;

inline char to_upper(char c)
{
    return c - 'a' + 'A';
}

inline char to_lower(char c)
{
    return c - 'A' + 'a';
}

inline bool is_upper(char c)
{
    return 'A' <= c && c <= 'Z';
}

int main()
{
    int nc;
    std::string name;

    std::cin >> nc >> name;
    nc--;

    std::string res[3];
    res[nc] = name;

    if (nc == NC_SNAKE)
    {
        std::string& camel = res[NC_CAMEL];

        bool cap = 0;
        for (char c : name)
        {
            if (c == '_')
                cap = 1;
            else
            {
                if (cap)
                {
                    camel.push_back(to_upper(c));
                    cap = 0;
                }
                else
                    camel.push_back(c);
            }
        }

        res[NC_PASCAL] = camel;
        res[NC_PASCAL][0] = to_upper(name[0]);
    }
    else
    {
        if (nc == NC_CAMEL)
        {
            res[NC_PASCAL] = name;
            res[NC_PASCAL][0] = to_upper(name[0]);
        }
        else // NC_PASCAL
        {
            res[NC_CAMEL] = name;
            res[NC_CAMEL][0] = to_lower(name[0]);
        }

        std::string& snake = res[NC_SNAKE];

        for (char c : res[NC_CAMEL])
        {
            if (is_upper(c))
            {
                snake.push_back('_');
                snake.push_back(to_lower(c));
            }
            else
                snake.push_back(c);
        }
    }

    for (auto& s : res)
        std::cout << s << '\n';
}