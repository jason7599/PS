#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int numSoldiers;
        cin >> numSoldiers;

        int maxCount = 0;
        long long maxNum = 0;
        bool done = 0;

        unordered_map<long long, int> count;

        for (int i = 0; i < numSoldiers; i++)
        {
            long long num;
            cin >> num;

            if (!done)
            {
                if (++count[num] > maxCount)
                {
                    maxCount = count[num];
                    maxNum = num;

                    if (maxCount > numSoldiers / 2)
                        done = 1;
                }
            }
        }

        if (done)
            cout << maxNum << '\n';
        else
            cout << "SYJKGW\n";
    }

    return 0;
}