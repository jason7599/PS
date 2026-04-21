#include <iostream>
#include <string>

bool solve(const std::string& str)
{
    if (str.empty())
        return 1;

    for (size_t i = 0; i < str.length(); i++)
    {
        size_t t = str.find_first_not_of(str[i], i + 1);
        size_t len = 
            (t == std::string::npos ? str.length() : t) - i;
        
        if (len > 1)
        {
            std::string popped = str;
            popped.erase(i, len);

            if (solve(popped))
                return 1;
        }
    }

    return 0;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_tc;
    std::cin >> n_tc;

    while (n_tc--)
    {
        std::string str;
        std::cin >> str;
        std::cout << solve(str) << '\n';
    }
}