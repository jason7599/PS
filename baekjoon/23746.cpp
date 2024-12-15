#include <iostream>
#include <string>
#include <map>

int main()
{
    int n_rules;
    std::cin >> n_rules;

    std::map<char, std::string> rules;

    while (n_rules--)
    {
        std::string str;
        char c;
        std::cin >> str >> c;
        rules[c] = str;
    }

    std::string funlockfile;
    std::cin >> funlockfile;

    size_t s, e;
    std::cin >> s >> e;

    std::string res;
    for (char c: funlockfile)
        res += rules.count(c) ? rules.at(c) : std::string(1, c);
    
    std::cout << res.substr(s - 1, e - s + 1);
}