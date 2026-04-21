#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_tc;
    std::cin >> n_tc;

    while (n_tc--)
    {
        int s, e;
        std::cin >> s >> e;
        
        int ans = 0;

        for (int i = s ; i <= e; i++)
        {
            std::string str = std::to_string(i);
            for (char c : str)
            {
                if (c == '0')
                    ans++;
            }
        }

        std::cout << ans << '\n';
    }
}