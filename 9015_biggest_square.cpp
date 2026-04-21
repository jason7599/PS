#include <iostream>
#include <cmath>
#include <algorithm>

struct Vector2
{
    int x, y;

    Vector2(int _x, int _y) : x(_x), y(_y) {}

    Vector2 operator+(const Vector2& other) const
    {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 operator-(const Vector2& other) const
    {
        return Vector2(x - other.x, y - other.y);
    }

    Vector2 operator-() const
    {
        return Vector2(-x, -y);
    }

    
};

bool is_square(const Vector2& p1, const Vector2& p2, const Vector2& p3, const Vector2& p4)
{
    -p1;
}

Vector2 points[3'000];

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int num_points;
        std::cin >> num_points;

        for (int p = 0; p < num_points; p++)
            std::cin >> points[p].x >> points[p].y;

        long long max_size;
    }
}