#include <iostream>
#include <string>
#include <algorithm>
#include <map>

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

const std::string hundos[] =
{
    "C", "CC", "CCC",
    "CD", "D", "DC",
    "DCC", "DCCC", "CM"
};

std::map<std::string, int> roman_to_int_table;
std::string int_to_roman_table[1001];

std::string int_to_roman(int n)
{
    if (n == 1000)
        return "M";
    
    std::string res;
    if (n >= 100)
    {
        res = hundos[n / 100 - 1];
        n %= 100;
    }
    if (n >= 10)
    {
        res += tens[n / 10 - 1];
        n %= 10;
    }
    if (n)
        res += ones[n - 1];

    return res;
}

void init_tables()
{
    for (int n = 1; n <= 1000; n++)
    {
        auto roman = int_to_roman(n);
        roman_to_int_table[roman] = n;
        int_to_roman_table[n] = roman;
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    init_tables();

    int n;
    std::cin >> n;
    while (n--)
    {
        std::string str;
        std::cin >> str;

        size_t p = str.find('+');

        std::string lhs = str.substr(0, p);
        std::string rhs = str.substr(p + 1, str.length() - (p + 1) - 1);
        
        int val = roman_to_int_table[lhs] + roman_to_int_table[rhs];

        std::cout << str;
        if (val > 1000)
            std::cout << "CONCORDIA CUM VERITATE\n";
        else
            std::cout << int_to_roman_table[val] << '\n';

        if (n)
            std::cout << '\n';
    }
}