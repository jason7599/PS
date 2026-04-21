#include <iostream>
#include <string>
#include <algorithm>

const std::string ones[] = 
{
    "I", "II", "III",
    "IV", "V", "VI",
    "VII", "VIII", "IX"
};

const std::string tens[] = 
{
    "X", "XX", "XXX",
    "XL", "L", "LX",
    "LXX", "LXXX", "XC"
};

std::string romanize(int n)
{
    std::string res;

    if (n > 9)
        res = tens[n / 10 - 1];
    res += ones[n % 10 - 1];

    return res;
}

int main()
{
    std::string num;
    std::cin >> num;

    std::sort(num.begin(), num.end());

    for (int n = 1; n <= 99; n++)
    {
        std::string roman = romanize(n);
        std::string t = roman;
        std::sort(t.begin(), t.end());

        if (num == t)
        {
            std::cout << roman;
            break;
        }
    }
}