#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int r, zr, zc;
    std::cin >> r >> zr >> zr >> zc;

    for (int i = 0; i < r; i++)
    {
        std::string s;
        std::cin >> s;

        std::string zs;
        zs.reserve(s.length() * zc);

        for (char c : s)
            zs += std::string(zc, c);

        for (int j = 0; j < zr; j++)
            std::cout << zs << '\n';
    }
}