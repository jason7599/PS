#include <iostream>
#include <vector>

std::vector<int> get_primes(int max_num)
{
    std::vector<bool> is_prime(max_num, 1);

    for (int i = 2; i * i <= max_num; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= max_num; j += i)
                is_prime[j] = 0;
        }
    }

    std::vector<int> primes({2});
    for (int i = 3; i <= max_num; i += 2)
    {
        if (is_prime[i])
            primes.push_back(i);
    }

    return primes;
}

int main()
{
    int num;
    std::cin >> num;

    if (num < 2)
        return 0;

    auto primes = get_primes(num);

    for (int n : primes)
    {
        while (num % n == 0)
        {
            std::cout << n << '\n';
            num /= n;
        }

        if (n == 1)
            break;
    }
}