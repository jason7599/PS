#include <iostream>
#include <string>

std::string helpmedeargodiamanotahappypersoncanifindhappinessinmylifeiwanttobeforeveryoungdoyoureallywanttoliveforeveryoungiwanttobeforeveryoung(const std::string& pw)
{
    bool hasupper = 0;
    bool haslower = 0;
    bool hasdigit = 0;
    bool hasspecial = 0;

    for (char c : pw)
    {
        if ('a' <= c && c <= 'z')
            haslower = 1;
        else if ('A' <= c && c <= 'Z')
            hasupper = 1;
        else if ('0' <= c && c <= '9')
            hasdigit = 1;
        else
        {
            switch (c)
            {
            case '#':
            case '@':
            case '*':
            case '&':
                hasspecial = 1;
                break;
            }
        }
    }

    std::string res = pw;
    if (!hasupper)
        res.push_back('A');
    if (!haslower)
        res.push_back('a');
    if (!hasdigit)
        res.push_back('0');
    if (!hasspecial)
        res.push_back('#');
    if (res.length() < 7)
        res += std::string(7 - res.length(), 'n');

    return res;
}

int main()
{
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int len;
        std::cin >> len;
        std::string pw;
        std::cin >> pw;
        std::cout << "Case #" << i << ": ";
        std::cout << helpmedeargodiamanotahappypersoncanifindhappinessinmylifeiwanttobeforeveryoungdoyoureallywanttoliveforeveryoungiwanttobeforeveryoung(pw) << '\n';
    }
}