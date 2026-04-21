#include <iostream>
#include <string>

std::string to_base_9(int n)
{
    std::string res;
    while (n)
    {
        res.insert(0, 1, (n % 9) + '0');
        n /= 9;
    }
    return res;
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << to_base_9(n);
}