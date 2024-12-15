#include <iostream>
#include <string>
#include <map>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::string words[6];
    for (auto& word : words)
        std::cin >> word;

    std::string ans;

    for (int w0 = 0; w0 <= 3; w0++)
    {
        for (int w1 = w0 + 1; w1 <= 4; w1++)
        {
            for (int w2 = w1 + 1; w2 <= 5; w2++)
            {
                std::string rows[] = {words[w0], words[w1], words[w2]};

                std::map<std::string, int> columns;
                for (int i = 0; i < 6; i++)
                {
                    if (i != w0 && i != w1 && i != w2)
                        columns[words[i]]++;
                }

                do
                {
                    auto bich = columns;
                    bool good = 1;

                    for (int col = 0; col < 3; col++)
                    {
                        std::string vword;
                        for (int row = 0; row < 3; row++)
                            vword += rows[row][col];
                        
                        if (bich[vword])
                            bich[vword]--;
                        else
                        {
                            good = 0;
                            break;
                        }
                    }

                    if (good)
                    {
                        std::string fuck;
                        for (auto& row : rows)
                            fuck += row;
                        
                        if (ans.empty() || fuck < ans)
                            ans = fuck;
                    }

                } while (std::next_permutation(rows, rows + 3));
            }
        }
    }

    if (ans.empty())
        std::cout << 0;
    else
    {
        for (int i = 0; i < 9; i++)
        {
            std::cout << ans[i];
            if ((i + 1) % 3 == 0)
                std::cout << '\n';
        }
    }
}