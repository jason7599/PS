#include <iostream>
#include <algorithm>

int seq[(int)2e6];

inline int log2(int n)
{
    int res = 0;
    while (n >>= 1)
        res++;
    return res;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int seq_len;
    std::cin >> seq_len;
    for (int i = 0; i < seq_len; i++)
        std::cin >> seq[i];

    std::sort(seq, seq + seq_len);

    int ans = 1;
    for (int i = 0; i < (seq_len + 1) / 2; i++)
        ans += log2(seq[i]);

    std::cout << ans;
}