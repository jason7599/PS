#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::list<char> chr_list;

    {
        std::string init_str;
        std::cin >> init_str;
        chr_list.assign(init_str.begin(), init_str.end());
    }

    auto it = chr_list.end();

    int n_commands;
    std::cin >> n_commands;

    while (n_commands--)
    {
        char op;
        std::cin >> op;

        switch (op)
        {
        case 'L':
            if (it != chr_list.begin())
                it--;
            break;

        case 'D':
            if (it != chr_list.end())
                it++;
            break;

        case 'B':
            if (it != chr_list.begin())
                it = chr_list.erase(--it);
            break;
            
        case 'P':
            char c;
            std::cin >> c;
            chr_list.insert(it, c);
            break;
        }
    }

    for (char c : chr_list)
        std::cout << c;
    std::cout << '\n';
}