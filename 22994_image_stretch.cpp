#include <iostream>
#include <string>

std::string image[1000];

int main()
{
    int img_height, img_width;
    std::cin >> img_height >> img_width;

    int xfac = img_width; // min streak
    int yfac = img_height;
    int ysrk = 1;
    for (int y = 0; y < img_height; y++)
    {
        std::cin >> image[y];

        if (y)
        {
            if (image[y - 1] == image[y])
                ysrk++;
            else
            {
                yfac = std::min(yfac, ysrk);
                ysrk = 1;
            }
        }

        int xsrk = 1;
        for (int x = 0; x < img_width; x++)
        {
            if (x)
            {
                if (image[y][x - 1] == image[y][x])
                    xsrk++;
                else
                {
                    xfac = std::min(xfac, xsrk);
                    xsrk = 1;
                }
            }
        }
    }

    if (img_height % yfac) 
        yfac = 1;
    if (img_width % xfac)
        xfac = 1;

    std::cout << img_height / yfac << ' ' << img_width / xfac << '\n';

    for (int y = 0; y < img_height; y += yfac)
    {
        for (int x = 0; x < img_width; x += xfac)
            std::cout << image[y][x];
        std::cout << '\n';
    }
}