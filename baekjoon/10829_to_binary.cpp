#include <iostream>
#include <string>

std::string to_binary(long long n)
{
    std::string res;
    while (n)
    {
        res.insert(0, 1, '0' + n % 2);
        n /= 2;
    }
    return res;
}

int main()
{
    long long n;
    std::cin >> n;
    std::cout << to_binary(n);
}