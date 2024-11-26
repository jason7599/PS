#include <iostream>

using namespace std;

int size_x, size_y;
int board[300][300];

void swap(int &x, int &y)
{
    int t = x;
    x = y;
    y = t;
}

void print_board(void)
{
    for (int x = 0; x < size_x; x++)
    {
        for (int y = 0; y < size_y; y++)
        {
            cout << board[x][y] << ' ';
        }
        cout << '\n';
    }
}

void rotate_layer(int layer, int len)
{

}

int main(void)
{
    int rot_iter;
    int rot_layers;

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> size_x >> size_y >> rot_iter;

    rot_layers = (size_x < size_y ? size_x : size_y) / 2;

    for (int x = 0; x < size_x; x++)
    {
        for (int y = 0; y < size_y; y++)
        {
            cin >> board[x][y];
        }
    }


}