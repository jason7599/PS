#include <iostream>
#include <algorithm>

using namespace std;

void print(char c, int n)
{
    while (n--)
        cout << c;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < 2 * n - 1; i++)
    {
        int t = n - abs(i - n + 1);
        
        print('*', t);
        print(' ', 2 * n -  2 * t);
        print('*', t);

        print('\n', 1);
    }

    return 0;
}