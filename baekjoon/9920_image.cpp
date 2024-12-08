#include <iostream>
#include <string>

std::string compress(bool image[64][64], int image_size, int y, int x)
{
    if (image_size == 1)
        return image[y][x] ? "01" : "00";

    int sub_size = image_size >> 1;

    std::string subs[4];

    for (int i = 0; i < 2; i++)
    {
        int nx = x + i * sub_size;
        for (int j = 0; j < 2; j++)
        {
            int ny = y + !j * sub_size;
            subs[i * 2 + j] = compress(image, sub_size, ny, nx);
        }
    }

    bool pure = 1;
    for (int i = 1; i < 4; i++)
    {
        if (subs[i] != subs[i - 1])
        {
            pure = 0;
            break;
        }
    }

    if (pure)
        return subs[0];
    
    std::string res = "1";
    for (const std::string& sub : subs)
        res += sub;
    
    return res;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int image_size;
    bool image[64][64];

    std::cin >> image_size;

    for (int i = 0; i < image_size; i++)
    {
        for (int j = 0; j < image_size; j++)
            std::cin >> image[i][j];
    }

    std::cout << compress(image, image_size, 0, 0).length();
}