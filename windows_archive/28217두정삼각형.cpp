#include <iostream>

using namespace std;

class Triangle
{
private:
    int size;
    bool vals[10][10];
    bool is_flipped = 0;
    int rot_clockwise = 0;
public:
    Triangle(int size)
    {
        this->size = size;
        for (int r = 0; r < size; r++)
            for (int c = 0; c < r + 1; c++)
                cin >> vals[r][c];
    }
    void rotate()
    {
        rot_clockwise = (rot_clockwise + 1) % 2;
    }
    void flip()
    {
        is_flipped = !is_flipped;
    }
    bool get_val(int row, int col)
    {
        
    }
    void print()
    {
        for (int r = 0; r < size; r++)
        {
            for (int c = 0; c < r + 1; c++)
                cout << get_val(r, c);
            cout << '\n';
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int size;
    cin >> size;

    Triangle tA(size);
    Triangle tB(size);

}