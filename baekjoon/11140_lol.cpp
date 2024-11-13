#include <iostream>
#include <string>
#include <algorithm>

int solve(const std::string& str)
{
    int ans = 3;

    size_t i = 0;
    while (i < str.length())
    {
        if (str[i] == 'l')
        {
            int t = 2;

            if (i != str.length() - 1)
            {
                if (str[i + 1] == 'o')
                {
                    t--;
                    i++;

                    if (i != str.length() - 1 && str[i + 1] == 'l')
                    {
                        ans = 0;
                        break;
                    }
                }
                else if (str[i + 1] == 'l')
                    t--;
                else if (i + 2 < str.length() && str[i + 2] == 'l')
                {
                    t--;
                    i++;
                }
            }

            ans = std::min(ans, t);
        }
        else if (str[i] == 'o')
        {
            int t = 2;
            
            if (i != str.length() - 1 && str[i + 1] == 'l')
            {
                t--;
                i++;
            }

            ans = std::min(ans, t);
        }

        i++;
    }

    return ans;
}

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        std::string str;
        std::cin >> str;
        std::cout << solve(str) << '\n';
    }
}