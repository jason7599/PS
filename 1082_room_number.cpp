#include <iostream>
#include <string>
#include <algorithm>

int num_numbers;
int min_price;
int prices[10];

// returns true if lhs < rhs
bool compare(const std::string& lhs, const std::string& rhs)
{
    if (lhs.length() == rhs.length())
    {
        for (size_t i = 0; i < lhs.length(); i++)
        {
            if (lhs[i] > rhs[i])
                return 0;
            if (lhs[i] < rhs[i])
                return 1;
        }
        return 0;
    }
    
    if (lhs.length() < rhs.length())
        return 1;

    return 0;
}

std::string solve(int money, bool init = 1)
{
    static std::string memo[51];

    if (money < min_price)
        return "";

    if (!memo[money].empty())
    {
        if (memo[money] == "-1")
            return "";
        return memo[money];
    }

    std::string res;
    for (int num = init; num < num_numbers; num++)
    {
        if (money >= prices[num])
        {
            std::string t = (char)(num + '0') + solve(money - prices[num], 0);
            res = std::max(res, t, compare);
        }
    }

    memo[money] = res.empty() ? "-1" : res;
    return res;
}

int main()
{
    std::cin >> num_numbers;
    std::cin >> prices[0];
    min_price = prices[0];
    for (int i = 1; i < num_numbers; i++)
    {
        std::cin >> prices[i];
        min_price = std::min(min_price, prices[i]);
    }
    
    int money;
    std::cin >> money;
    std::string t = solve(money);
    std::cout << (t.empty() ? "0" : t);
}