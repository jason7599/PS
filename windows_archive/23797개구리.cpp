#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    char c;
    int k = 0;
    int p = 0;
    while ((c = getchar()) != '\n')
    {
        if (c == 'K')
        {
            if (k)
                k--;
            p++;
        }
        else
        {
            if (p)
                p--;
            k++;
        }
    }
    cout << k + p;
    return 0;
}