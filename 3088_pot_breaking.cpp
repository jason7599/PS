#include <iostream>

bool set[(int)1e6 + 1];

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_pots;
    std::cin >> n_pots;

    int ans = 0;

    while (n_pots--)
    {
        bool overlap = 0;
        for (int i = 0; i < 3; i++)
        {
            int num;
            std::cin >> num;
            if (!set[num])
                set[num] = 1;
            else
                overlap = 1;
        }

        if (!overlap)
            ans++;
    }

    std::cout << ans;
}