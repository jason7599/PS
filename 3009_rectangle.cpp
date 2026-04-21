#include <iostream>
#include <map>

int main()
{
    std::map<int, int> fuck[2];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int x;
            std::cin >> x;
            fuck[j][x]++;
        }
    }

    for (const auto& fck : fuck)
    {
        for (const auto& [x, cnt] : fck)
        {
            if (cnt == 1)
            {
                std::cout << x << ' ';
                break;
            }
        }
    }
}