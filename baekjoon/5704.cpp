#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    
    while (1)
    {
        std::string line;
        std::getline(std::cin, line);

        if (line == "*")
            break;

        int cnt[26] = {0};
        int nzcnt = 26;

        for (char c : line)
        {
            int i = c - 'a';
            if (0 <= i && i < 26)
            {
                if (!cnt[i]++)
                    nzcnt--;
            }
        }

        std::cout << (nzcnt ? 'N' : 'Y') << '\n';
    }
}