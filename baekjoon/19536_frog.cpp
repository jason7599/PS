#include <iostream>

bool is_possible(int x, int y, int moves)
{
    int nig = abs(x) + abs(y);
    if (nig > moves)
        return 0;
    return nig % 2 == moves % 2;
}

int main()
{
    int x, y, moves;
    std::cin >> x >> y >> moves;
    std::cout << (is_possible(x, y, moves) ? "YES" : "NO") << '\n';
}