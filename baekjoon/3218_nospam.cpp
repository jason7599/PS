#include <iostream>
#include <string>
#include <set>

std::set<std::string> cok;

void unscramble(const std::string& str)
{
    size_t b = 0;
    size_t t;
    while ((t = str.find("at", b)) != std::string::npos)
    {
        b = t + 2;

        if (t && str[t - 1] != '.'
        && t + 2 < str.length() && str[t + 2] != '.')
        {
            std::string bitch = str.substr(0, t) + '@' + str.substr(t + 2); 
            if (bitch.front() != '.' and bitch.back() != '.')
                cok.insert(bitch);
        }
    }
}

int main()
{
    std::string str;
    std::cin >> str;

    unscramble(str);

    size_t b = 0;
    size_t t;
    while ((t = str.find("nospam", b)) != std::string::npos)
    {
        b = t + 6;
        unscramble(str.substr(0, t) + str.substr(t + 6));
    }

    for (const auto& co : cok)
        std::cout << co << '\n';
}
