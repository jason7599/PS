#include <iostream>
#include <string>

// count number of numbers that start with `start` of len `len`
uint64_t count(int start, int len)
{
    static uint64_t cache[10][81];

    if (len == 1)
        return 1;
    
    if (cache[start][len])
        return cache[start][len];
    
    uint64_t res = 0;
    for (int next = start; next <= 9; next++)
        res += count(next, len - 1);
    
    return cache[start][len] = res;
}

bool is_increasing_num(const std::string& num)
{
    for (size_t i = 1; i < num.length(); i++)
    {
        if (num[i - 1] > num[i])
            return 0;
    }
    return 1;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_tc;
    std::cin >> n_tc;

    while (n_tc--)
    {
        std::string num;
        std::cin >> num;

        if (!is_increasing_num(num))
            std::cout << -1 << '\n';
        else
        {
            size_t len = num.length();

            // hax. counts ALL the inc. nums of len <= `len` by allowing leading zeros
            uint64_t ans = count(0, len + 1);

            for (size_t i = 0; i < len; i++)
            {
                for (int start = num[i] - '0' + 1; start <= 9; start++)
                    ans -= count(start, len - i);
            }

            // exclude num itself
            std::cout << ans - 1 << '\n';
        }
    }
}