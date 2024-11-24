#include <iostream>

int img_h, img_w;
int img[50][50];
int overlap[50];

const int p_r = 0;
const int p_g = 1;
const int p_b = 2;
const int p_t = 3;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    uint cnt[3] = {0};

    int rep;
    std::cin >> img_h >> img_w >> rep;
    for (int y = 0; y < img_h; y++)
    {
        for (int x = 0; x < img_w; x++)
        {
            char c;
            std::cin >> c;
            int p;
            switch (c)
            {
            case 'R': p = p_r; break;
            case 'G': p = p_g; break;
            case 'B': p = p_b; break;
            case '.': p = p_t; continue;
            }
            img[y][x] = p;
            cnt[p]++;
        }
    }


}