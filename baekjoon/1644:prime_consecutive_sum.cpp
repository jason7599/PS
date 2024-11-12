#include <iostream>
#include <vector>

const int max_val = 4e6;

std::vector<int> get_primes(int val)
{
    static bool is_composite[max_val + 1];

    if (val == 1)
        return {};

    for (int i = 2; i * i <= val; i++)
    {
        if (!is_composite[i])
        {
            for (int j = i * i; j <= val; j += i)
                is_composite[j] = 1;
        }
    }

    std::vector<int> res({2});
    for (int i = 3; i <= val; i += 2)
    {
        if (!is_composite[i])
            res.push_back(i);
    }
    return res;
}

int main()
{
    int n;
    std::cin >> n;

    auto primes = get_primes(n);

    int ans = 0;
    int r = 0;
    int sum = 0;
    for (int l = 0; l < primes.size(); l++)
    {
        while (r < primes.size() && sum < n)
            sum += primes[r++];
        
        if (sum == n)
            ans++;
        
        sum -= primes[l];
    }

    std::cout << ans;
}