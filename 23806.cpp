#include <iostream>
#include <string>

inline void printc(int n)
{
    std::cout << std::string(n, '@');
}

inline void printb(int n)
{
    std::cout << std::string(n, ' ');
}

inline void newline()
{
    std::cout << '\n';
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int size;
    std::cin >> size;

    for (int i = 0; i < size; i++)
        printc(size * 5), newline();
    
    for (int i = 0; i < size * 3; i++)
        printc(size), printb(size * 3), printc(size), newline();

    for (int i = 0; i < size; i++)
        printc(size * 5), newline();
}