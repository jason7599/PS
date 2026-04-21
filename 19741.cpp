#include <iostream>
#include <algorithm>

int divisor_cnt[40 * 40 + 1];

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n, k;
    std::cin >> n >> k;

    std::fill(&divisor_cnt[2], &divisor_cnt[1 + n * n], 2);
    divisor_cnt[1] = 1;

    for (int i = 2; i <= n * n; i++)
    {
        for (int j = 2 * i; j <= n * n; j += i)
            divisor_cnt[j]++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << (divisor_cnt[i * n + j + 1] <= k ? '*' : '.');
        std::cout << '\n';
    }
}