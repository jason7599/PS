#include <iostream>
#include <bitset>
#include <algorithm>

int size;
std::bitset<20> rows[20]; // 1 = T
std::bitset<20> cols[20];

int main()
{
    std::cin >> size;
    int ans = 0;
    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            char c;
            std::cin >> c;
            rows[y].set(x, c == 'T');
            cols[x].set(y, c == 'T');
            ans += c == 'T';
        }
    }

    
}