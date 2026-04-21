#include <iostream>
#include <map>

int main()
{
    int arr_len, mod;
    std::cin >> arr_len >> mod;

    std::map<int, int> mod_cnt;

    mod_cnt[0] = 1; // 0
    int sum = 0;
    while (arr_len--)
    {
        int x;
        std::cin >> x;
        sum = (sum + (x % mod)) % mod;
        mod_cnt[sum]++;
    }

    long long ans = 0;
    for (const auto& [i, cnt] : mod_cnt)
        ans += (long long)cnt * (cnt - 1) / 2;
    std::cout << ans;
}