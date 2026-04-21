#include <iostream>
#include <vector>

std::vector<int> convert(uint64_t num, int base)
{
    std::vector<int> res;

    while (num)
    {
        res.push_back(num % base);
        num /= base;
    }

    return res;
}

bool is_palindrome(const std::vector<int>& vec)
{
    for (size_t i = 0; i < vec.size() / 2; i++)
    {
        if (vec[i] != vec[vec.size() - 1 - i])
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
        uint64_t num;
        int base;
        std::cin >> num >> base;
        std::cout << is_palindrome(convert(num, base)) << '\n';
    }
}