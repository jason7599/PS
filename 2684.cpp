#include <iostream>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_tc;
    std::cin >> n_tc;

    int res[8] = {};
    
    while (n_tc--)
    {
        int val = 0;
        for (int i = 0; i < 3; i++)
        {
            char c;
            std::cin >> c;
            val = val * 2 + (c == 'H');
        }

        res[val] = 1;

        for (int i = 3; i < 40; i++)
        {
            char c;
            std::cin >> c;
            val = ((val % 4) << 1) + (c == 'H');
            res[val]++;
        }

        for (int i = 0; i < 8; i++)
        {
            std::cout << res[i] << ' ';
            res[i] = 0;
        }
        std::cout << '\n';
    }
}