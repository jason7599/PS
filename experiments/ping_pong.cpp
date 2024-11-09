#include <iostream>

// [1, range] inclusive
int ping_pong(int pos, int range)
{
    int cycle = 2 * (range - 1);
    int mod_pos = (pos - 1) % cycle; // zero based position within the cycle

    if (mod_pos < 0)
        mod_pos += cycle; // ensure positive mod value
    
    if (mod_pos < range - 1) // ascending part
        return mod_pos + 1;

    return cycle - mod_pos + 1; // descending part
}

int main()
{
    int range;
    std::cin >> range;

    for (int pos = -range * 4; pos <= range * 4; pos++)
        std::cout << pos << " -> " << ping_pong(pos, range) << '\n';
}