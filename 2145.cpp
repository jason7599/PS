#include <iostream>

int solve(int n)
{
    int res = n;

    while (res > 9)
    {
        int sum = 0;
        while (res)
        {
            sum += res % 10;
            res /= 10;
        }
        res = sum;
    }

    return res;
}

int main()
{
    while (1)
    {
        int n;
        std::cin >> n;
        if (!n)
            break;
        
        std::cout << solve(n) << '\n';
    }
}