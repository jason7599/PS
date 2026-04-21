#include <iostream>
#include <string>

const std::pair<char, int> negors[] =
{
    {'m', 1000},
    {'c', 100},
    {'x', 10},
    {'i', 1}
};

int mcxi_to_int(const std::string& mcxi)
{
    int res = 0;
    int qt = 1;
    for (char c : mcxi)
    {
        if ('2' <= c && c <= '9')
            qt = c - '0';
        else
        {
            for (auto [_c, v] : negors)
            {
                if (c == _c)
                {
                    res += v *  qt;
                    break;
                }
            }
            qt = 1;
        }
    }

    return res;
}

std::string int_to_mcxi(int n)
{
    std::string mcxi;

    for (const auto& [c, v] : negors)
    {
        if (n >= v)
        {
            if (n >= 2 * v)
                mcxi.push_back('0' + n / v);
            mcxi.push_back(c);
            n %= v;
        }
    }

    return mcxi;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int t;
    std::cin >> t;

    while (t--)
    {
        std::string mcxi0, mcxi1;
        std::cin >> mcxi0 >> mcxi1;

        int sum = mcxi_to_int(mcxi0) + mcxi_to_int(mcxi1);
        std::cout << int_to_mcxi(sum) << '\n';
    }
}