#include <iostream>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int a_pos[101];
    int a_cnt = 0;

    int n_sum[101];
    n_sum[0] = 0;

    int len;
    std::cin >> len;

    for (int i = 1; i <= len; i++)
    {
        char c;
        std::cin >> c;

        n_sum[i] = n_sum[i - 1];

        if (c == 'A')
            a_pos[a_cnt++] = i;
        else if (c == 'N')
            n_sum[i]++;
    }

    int ans = 0;
    for (int ai = 0; ai < a_cnt - 1; ai++)
    {
        if (n_sum[a_pos[ai + 1]] - n_sum[a_pos[ai]] == 1)
            ans++;
    }

    std::cout << ans;
}