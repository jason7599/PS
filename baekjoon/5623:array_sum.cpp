#include <iostream>

int sum[1000][1000];

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int size;
    std::cin >> size;
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cin >> sum[i][j];
        }
    }
    
    if (size <= 2)
    {
        std::cout << "1 1";
    }
    else
    {
        // a + b    +   a + c   -   (b + c)
        int a = (sum[0][1] + sum[0][2] - sum[1][2]) / 2;
        std::cout << a << ' ';
        for (int i = 1; i < size; i++)
            std::cout << sum[0][i] - a << ' ';
    }
}