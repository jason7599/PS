#include <iostream>
#include <algorithm>

using namespace std;

int triangle_size;
int triangle[500][500];

int main()
{
    cin >> triangle_size;
    for (int row = 0; row < triangle_size; row++)
    {
        for (int col = 0; col <= row; col++)
            cin >> triangle[row][col];
    }

    for (int row = triangle_size - 2; row >= 0; row--)
    {
        for (int col = 0; col <= row; col++)
            triangle[row][col] += max(triangle[row + 1][col], triangle[row + 1][col + 1]);
    }

    cout << triangle[0][0];
}