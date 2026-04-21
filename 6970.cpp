#include <iostream>
#include <string>

int cnt[3];
std::string words[3][20];

void fuck(int i = 0)
{
    static int opt[3];

    if (i == 3)
    {
        for (int j = 0; j < 2; j++)
            std::cout << words[j][opt[j]] << ' ';
        std::cout << words[2][opt[2]] << ".\n";
        return;
    }
    
    for (int j = 0; j < cnt[i]; j++)
    {
        opt[i] = j;
        fuck(i + 1);
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        for (int i = 0; i < 3; i++)
            std::cin >> cnt[i];
        
        std::cin.ignore();

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < cnt[i]; j++)
                std::getline(std::cin, words[i][j]);
        }

        fuck();

        if (t)
            std::cout << '\n';
    }
}