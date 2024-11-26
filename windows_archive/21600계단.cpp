#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    int max_len = 0;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        if (len + 1 <= h)
        {
            if (++len > max_len)
                max_len = len;
        }
        else
            len = h;
    }

    cout << max_len;
    return 0;
}