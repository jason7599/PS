#include <iostream>

using namespace std;

int root[300'001];

int find_root(int element)
{
    if (element != root[element])
        root[element] = find_root(root[element]);
    return root[element];
}

int main()
{
    int num_islands;
    cin >> num_islands;

    for (int i = 1; i <= num_islands; i++)
        root[i] = i;

    for (int i = 0; i < num_islands - 2; i++)
    {
        int x, y; 
        cin >> x >> y;

        x = find_root(x);
        y = find_root(y);

        if (x < y) root[y] = x;
        else root[x] = y;
    }

    int a = find_root(1);
    cout << a << ' ';

    for (int b = 2; b <= num_islands; b++)
        if (find_root(b) != a)
        {
            cout << b;
            return 0;
        }
}