#include <iostream>

using namespace std;

int flip(int x)
{
    int res = 0;
    while (x)
    {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;

    int max = 0;
    for (int i = 1; i <= k; i++)
    {
        int x = flip(n * i);
        if (x > max)
            max = x;
    }
    cout << max;
    return 0;
}