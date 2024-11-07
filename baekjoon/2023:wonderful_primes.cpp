#include <iostream>

bool is_prime(int n)
{
    if (n == 1)
        return 0;
    
    if (n == 2)
        return 1;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void solve(const int len, int num = 0, int digit = 0)
{
    if (digit == len)
    {
        std::cout << num << '\n';
        return;
    }

    for (int i = (digit ? 0 : 2); i < 10; i++)
    {
        int next_num = num * 10 + i;
        if (is_prime(next_num))
            solve(len, next_num, digit + 1);
    }
}

int main()
{
    int len;
    std::cin >> len;
    solve(len);
}