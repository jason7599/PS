#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    n ^= -n;
    int ans = 0;
    for (int i = 0; i < 32; i++)
    {
        if ((n >> i) & 1)
            ans++;
    }
    std::cout << ans;
}