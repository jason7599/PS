#include <iostream>
#include <string>

std::string binary_add(const std::string& lhs, const std::string& rhs)
{
    std::string res;

    size_t l = lhs.length();
    size_t r = rhs.length();
    bool carry = 0;
    while (l > 0 || r > 0)
    {
        int lval = l > 0 ? lhs.at(--l) == '1' : 0;
        int rval = r > 0 ? rhs.at(--r) == '1' : 0;

        int val = (lval + rval + carry) % 2;
        carry = (lval + rval + carry) >= 2;

        res = (char)(val + '0') + res;
    }

    if (carry)
        res = '1' + res;

    return res;
}

void strip_leading_zeros(std::string& str)
{
    size_t t = str.find('1');
    if (t == std::string::npos) // all zeros
        str = "0";
    else
        str.erase(0, t);
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    
    int n_tc;
    std::cin >> n_tc;

    while (n_tc--)
    {
        std::string lhs, rhs;
        std::cin >> lhs >> rhs;

        strip_leading_zeros(lhs);
        strip_leading_zeros(rhs);

        std::cout << binary_add(lhs, rhs) << '\n';
    }
}