#include <bits/stdc++.h>

struct Pos
{
    int x;
    int y;
};

Pos solve(int len, int step)
{
    assert(len != 1);

    if (len == 2)
    {
        switch (step)
        {
            case 1: return Pos{1, 1};
            case 2: return Pos{1, 2};
            case 3: return Pos{2, 2};
            case 4: return Pos{2, 1};
        }

        assert(0);
    }

    int sublen = len >> 1;
    int subsize = pow(sublen, 2);
    int quad_num = (step - 1) / subsize + 1;

    Pos base;
    if (quad_num == 4)
    {
        base.x = len + 1;
        base.y = sublen + 1;
    }
    else
    {
        base.x = quad_num <= 2 ? 0 : sublen;
        base.y = quad_num / 2 == 1 ? sublen : 0;
    }

    Pos next = solve(sublen, step - subsize * (quad_num - 1));

    if (quad_num / 2 != 1 && next.x != next.y)
    {
        int t = next.x;
        next.x = next.y;
        next.y = t;
    }

    if (quad_num == 4)
    {
        next.x *= -1;
        next.y *= -1;
    }

    return Pos{base.x + next.x, base.y + next.y};
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int len, step;
    std::cin >> len >> step;

    Pos pos = solve(len, step);
    std::cout << pos.x << ' ' << pos.y << '\n';
}