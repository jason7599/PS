#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    int char_cnts[2][26] = {};

    for (int i = 0; i < 2; i++)
    {
        std::string str;
        std::cin >> str;
        for (char c : str)
            char_cnts[i][c - 'a']++;
    }

    int ans = 0;
    for (int i = 0; i < 26; i++)
        ans += std::abs(char_cnts[0][i] - char_cnts[1][i]);

    std::cout << ans;
}