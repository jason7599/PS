#include <iostream>

int main()
{
    int len;
    std::cin >> len;

    const char goristr[] = "gori";
    int goriidx = 0;

    bool good = 0;
    for (int i = 0; i < len; i++)
    {
        char c;
        std::cin >> c;

        if (good) continue;

        if (c == goristr[goriidx])
        {
            if (++goriidx == 4)
                good = 1;
        }
        else
            goriidx = 0;
    }

    if (good)
        std::cout << "YES";
    else
        std::cout << "NO";
}