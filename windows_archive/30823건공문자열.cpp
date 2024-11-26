#include <iostream>
#include <string>

using namespace std;

int main()
{
    int len, k;
    cin >> len >> k;

    string str;
    cin >> str;

    int x = len - k + 1;
    for (int i = k - 1; i < k - 1 + x; i++)
        cout << str[i];

    int y, dy;
    if (x % 2 == 0)
    {
        y = 0;
        dy = 1;
    }
    else
    {
        y = k - 2;
        dy = -1;
    }

    for (int i = 0; i < k - 1; i++)
    {
        cout << str[y];
        y += dy;
    }

    return 0;
}