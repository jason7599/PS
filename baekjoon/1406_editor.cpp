#include <iostream>
#include <string>
#include <list>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::string raw;
    std::cin >> raw;

    std::list<char> list(raw.begin(), raw.end());

    auto i = list.end();
    
    int n_cmds;
    std::cin >> n_cmds;
    while (n_cmds--)
    {
        char cmd;
        std::cin >> cmd;

        switch (cmd)
        {
        case 'L':
            if (i != list.begin())
                i--;
            break;
        
        case 'D':
            if (i != list.end())
                i++;
            break;
        
        case 'B':
            if (i != list.begin())
                i = list.erase(--i);
            break;

        case 'P':
            char c;
            std::cin >> c;
            list.insert(i, c);
            break;
        }
    }

    std::cout << std::string(list.begin(), list.end());
}