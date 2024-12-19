#include <iostream>
#include <string>

int main()
{
    std::string horiz, verti;
    std::cin >> horiz >> verti;

    // find the first common letter
    size_t horiz_i, verti_i;

    for (horiz_i = 0;; horiz_i++)
    {
        for (verti_i = 0; verti_i < verti.length() && horiz[horiz_i] != verti[verti_i]; verti_i++);
        if (verti_i < verti.length())
            break;
    }

    for (size_t y = 0; y < verti.length(); y++)
    {
        if (y == verti_i)
            std::cout << horiz;
        else
        {
            for (size_t x = 0; x < horiz.length(); x++)
            {
                if (x == horiz_i)
                    std::cout << verti[y];
                else
                    std::cout << '.';
            }
        }
        std::cout << '\n';
    }
}
