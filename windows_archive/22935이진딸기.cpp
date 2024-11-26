#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        x = (x - 1) % 28 + 1;
        if (x > 15)
            x = 30 - x;
        for (int d = 3; d >= 0; d--)
        {
            if ((x >> d) & 1)
                cout << "딸기";
            else
                cout << 'V';
        }
        cout << '\n';
    }
    return 0;
}