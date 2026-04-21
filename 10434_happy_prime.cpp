#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>

const int max_num = 10000;

bool is_prime[max_num + 1];

void sieve()
{
    std::fill(&is_prime[0], &is_prime[max_num + 1], 1);

    is_prime[1] = 0;
    for (int i = 2; i * i <= max_num; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= max_num; j += i)
                is_prime[j] = 0;
        }
    }
}

bool is_happy(int num)
{
    std::set<int> v({num});

    while (1)
    {
        if (num == 1)
            return 1;

        int nx_num = 0;
        while (num)
        {
            nx_num += std::pow(num % 10, 2);
            num /= 10;
        }

        if (v.count(nx_num))
            return 0;
        
        v.insert(nx_num);
        num = nx_num;
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    sieve();

    int n_tc;
    std::cin >> n_tc;
    while (n_tc--)
    {
        int tc_no, num;
        std::cin >> tc_no >> num;
        std::cout << tc_no << ' ' << num << ' '
            << ((is_prime[num] && is_happy(num)) ? "YES" : "NO") << '\n';
    }
}