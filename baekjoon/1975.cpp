#include <iostream>

int cnt_zeros(int n, int b)
{
    if (n % b)
        return 0;

    n /= b;
    int cnt = 1;
    while (n)
    {
        if (n % b)
            break;
        
        cnt++;
        n /= b;
    }

    return cnt;
}

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        int ans = 1;
        for (int i = 2; i < n; i++)
            ans += cnt_zeros(n, i);
        std::cout << ans << '\n';
    }
}