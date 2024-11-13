#include <iostream>
#include <algorithm>
#include <cmath>

struct Coords
{
    int y, x;

    Coords operator+(const Coords& other) const
    {
        return Coords{y + other.y, x + other.x};
    }

    Coords operator-(const Coords& other) const
    {
        return Coords{-y, -x} + other;
    }

    bool operator==(const Coords& other) const
    {
        return y == other.y && x == other.x;
    }

    bool operator!=(const Coords& other) const
    {
        return !(*this == other);
    }

    long long magnitude() const
    {
        return std::pow(y, 2) + std::pow(x, 2);
    }

    static bool compare(const Coords& lhs, const Coords& rhs)
    {
        if (lhs.y == rhs.y)
            return lhs.x < rhs.x;
        return lhs.y < rhs.y;
    }
};

int main()
{
    Coords coords[4];

    int t;
    std::cin >> t;
    while (t--)
    {
        for (int i = 0; i < 4; i++)
            std::cin >> coords[i].y >> coords[i].x;

        std::sort(coords, coords + 4, Coords::compare);
    
        Coords dx = coords[2] - coords[0];
        if (dx != coords[3] - coords[1])
        {
            std::cout << 0 << '\n';
            continue;
        }
        
        Coords dy = coords[1] - coords[0];
        if (dy != coords[3] - coords[2])
        {
            std::cout << 0 << '\n';
            continue;
        }

        Coords dd = coords[1] - coords[2];
        if (dd.magnitude() != (coords[3] - coords[0]).magnitude())
        {
            std::cout << 0 << '\n';
            continue;
        }

        std::cout << (dx.magnitude() == dy.magnitude()) << '\n';
    }
}