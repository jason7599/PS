#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>

struct RomanValue
{
    int value;
    std::set<char> precedes;
};

const std::map<char, RomanValue> roman_vals = 
{
    {'I', {1, {'V', 'X'}}},
    {'V', {5, {}}},
    {'X', {10, {'L', 'C'}}},
    {'L', {50, {}}},
    {'C', {100, {'D', 'M'}}},
    {'D', {500, {}}},
    {'M', {1000, {}}}
};

std::map<int, std::string> init_int_to_roman_table()
{
    std::map<int, std::string> table;

    for (const auto& [c, roman_value] : roman_vals)
    {
        table[roman_value.value] = c;
        if (!roman_value.precedes.empty())
        {
            for (char successor : roman_value.precedes)
                table[roman_vals.at(successor).value - roman_value.value]
                    = std::string(1, c) + successor;

            for (int i = 2; i <= 3; i++)
                table[roman_value.value * i] = std::string(i, c);
        }
        
    }

    return table;
}

const std::map<int, std::string> int_to_roman = init_int_to_roman_table();

int get_val(const std::string& str)
{
    int val = 0;
    size_t pos = 0;
    while (pos < str.length())
    {
        char c = str[pos];
        RomanValue number = roman_vals.at(c);

        if (pos + 1 < str.length()
            && number.precedes.find(str[pos + 1]) != number.precedes.end())
        {
            val += roman_vals.at(str[pos + 1]).value - number.value;
            pos += 2;
        }
        else
        {
            val += number.value;
            pos++;
        }
    }

    return val;
}

std::string romanize(int value)
{
    std::string res;

    while (value)
    {
        for (auto iter = int_to_roman.rbegin(); iter != int_to_roman.rend(); iter++)
        {
            if (value >= iter->first)
            {
                res += iter->second;
                value -= iter->first;
                break;
            }
        }
    }

    return res;
}

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        std::string line;
        std::cin >> line;

        size_t sep = line.find('+');

        std::string lhs = line.substr(0, sep);
        std::string rhs = line.substr(sep + 1, line.length() - sep - 2);

        int sum = get_val(lhs) + get_val(rhs);
        if (sum > 1000)
            std::cout << "CONCORDIA CUM VERITATE\n";
        else
            std::cout << line << romanize(sum) << '\n';
        
        if (t)
            std::cout << '\n';
    }
}