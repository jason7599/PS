#include <iostream>
#include <vector>
#include <cstring>

const int MAX_NUM = 1e8;

bool is_prime[MAX_NUM + 1];
std::vector<int> primes_list;

void init_primes()
{
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = 0;

    for (int i = 2; i * i <= MAX_NUM; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= MAX_NUM; j += i)
                is_prime[j] = 0;
        }
    }

    primes_list.push_back(2);
    for (int i = 3; i <= MAX_NUM; i += 2)
    {
        if (is_prime[i])
            primes_list.push_back(i);
    }
}

// what number to use next
int dp[MAX_NUM + 1][5];

int solve(int num, int k)
{
    if (!num)
        return k ? -1 : 1;
    
    if (!k)
        return -1;

    if (dp[num][k])
        return dp[num][k];

    for (int prime : primes_list)
    {
        if (prime > num)
            break;
        
        if (solve(num - prime, k - 1) != -1)
            return dp[num][k] = prime;
    }

    return dp[num][k] = -1;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    init_primes();

    int num;
    while (std::cin >> num)
    {
        if (solve(num, 4) == -1)
            std::cout << "Impossible.\n";
        else
        {
            for (int i = 4; i > 0; i--)
            {
                std::cout << dp[num][i] << ' ';
                num -= dp[num][i];
            }
            std::cout << '\n';
        }
    }
}