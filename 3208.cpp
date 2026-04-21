#include <iostream>

int gus(int r, int c)
{
    if (r == 1)
        return 0;
    
    return 1 + gus(c, r - 1);
}

int main()
{
    int r, c;
    std::cin >> r >> c;
    std::cout << gus(r, c);
}