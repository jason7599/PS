#include <iostream>

using namespace std;

int main()
{
    int val;
    cin >> val;

    int n = 1;
    while (val != 1)
    {
        if (val % 2 == 0)
            val /= 2;
        else
            val = val * 3 + 1;
        
        n++;
    }

    cout << n;
    return 0;
}