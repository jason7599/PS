#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define 정수 int
#define 메인 main

정수 pool(const int image[1024][1024], int size, int y, int x)
{
    if (size == 1)
        return image[y][x];

    int sub_size = size / 2;
    vector<int> vec;

    for (int i = 0; i < 2; i++)
    {
        int yy = y + sub_size * i;
        for (int j = 0; j < 2; j++)
        {
            int xx = x + sub_size * j;
            vec.push_back(pool(image, sub_size, yy, xx));
        }
    }

    sort(vec.begin(), vec.end());
    return vec[2];
}

정수 메인()
{
    int image_size;
    static int image[1024][1024];
    
    cin >> image_size;

    for (int y = 0; y < image_size; y++)
    {
        for (int x = 0; x < image_size; x++)
            cin >> image[y][x];
    }

    cout << pool(image, image_size, 0, 0);

    return 0;
}