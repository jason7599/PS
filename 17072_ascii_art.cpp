#include <iostream>

using namespace std;

int get_intensity(int r, int g, int b)
{
    return 2126 * r + 7152 * g + 722 * b;
}

char ptoc(int intensity)
{
    if (intensity >= 2'040'000)
        return '.';
    if (intensity >= 1'530'000)
        return '-';
    if (intensity >= 1'020'000)
        return '+';
    if (intensity >= 510'000)
        return 'o';
    return '#';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int image_height, image_width;
    cin >> image_height >> image_width;
    for (int y = 0; y < image_height; y++)
    {
        for (int x = 0; x < image_width; x++)
        {
            int r, g, b;
            cin >> r >> g >> b;
            cout << ptoc(get_intensity(r, g, b));
        }
        cout << '\n';
    }

    return 0;
}