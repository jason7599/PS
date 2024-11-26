#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int i = 0, x = 665;

    while (i != n)
    {
        int y = ++x;
        int c = 0;
        while (y)
        {
            if (y % 10 == 6) 
            {
                if (++c == 3) break;
            }
            else c = 0;
            y /= 10;
        }
        if (c == 3) i++;
    }

    cout << x;


}