#include <iostream>

using namespace std;

int graph[999][999];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1}; // up, right, down, left

void solve(int dimension, int targetNumber)
{
    int x = dimension / 2;
    int y = dimension / 2;
    int directionIndex = 0;
    int length = 1;
    int number = 1;

    int targetX, targetY;

    while (number <= dimension * dimension)
    {
        for (int i = 0; i < length; i++)
        {
            graph[x][y] = number;

            if (number == targetNumber)
            {
                targetX = x + 1;
                targetY = y + 1;
            }

            number++;

            x += dx[directionIndex];
            y += dy[directionIndex];
        }

        if (directionIndex % 2)
            length++;

        if (++directionIndex == 4)
            directionIndex = 0;
    }

    for (x = 0; x < dimension; x++)
    {
        for (y = 0; y < dimension; y++)
        {
            cout << graph[x][y] << ' ';
        }
        cout << '\n';
    }
    
    cout << targetX << ' ' << targetY;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int dimension, targetNumber;
    cin >> dimension >> targetNumber;

    solve(dimension, targetNumber);

    return 0;
}