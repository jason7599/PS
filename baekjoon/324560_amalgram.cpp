#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    int cnts[2][26] = {};

    for (int i = 0; i < 2; i++)
    {
        std::string word;
        std::cin >> word;
        for (char c : word)
            cnts[i][c - 'a']++;
    }

    for (int i = 0; i < 26; i++)
        std::cout << std::string(std::max(cnts[0][i], cnts[1][i]), i + 'a');
}