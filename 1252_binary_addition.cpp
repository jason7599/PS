#include <iostream>
#include <string>

std::string add(std::string lhs, std::string rhs)
{
    size_t t;
    if ((t = lhs.find('1')) != std::string::npos)
        lhs = lhs.substr(t);
    else
        lhs = "0";
    
    if ((t = rhs.find('1')) != std::string::npos)
        rhs = rhs.substr(t);
    else
        rhs = "0";

    std::string res;

    size_t l = lhs.size();
    size_t r = rhs.size();

    bool carry = 0;
    while (l || r)
    {
        int lv = l ? lhs[--l] == '1' : 0;
        int rv = r ? rhs[--r] == '1' : 0;
        int v = lv + rv + carry;

        res.insert(0, 1, v % 2 ? '1' : '0');
        carry = v > 1;
    }
    if (carry)
        res.insert(0, 1, '1');

    return res;
}

int main()
{
    std::string lhs, rhs;
    std::cin >> lhs >> rhs;
    std::cout << add(lhs, rhs);
}