#include <iostream>

using namespace std;

bool isIn[200'001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int numLogs;
    cin >> numLogs;

    int ans = 0;
    int inCount = 0;

    for (int i = 0; i < numLogs; i++)
    {
        int who;
        bool in;
        cin >> who >> in;

        if (isIn[who] == in)
        {
            ans++;
        }
        else
        {
            if (in)
            {
                inCount++;
            }
            else
            {
                inCount--;
            }

            isIn[who] = in;
        }
    }

    cout << ans + inCount;
}