#include <iostream>

using namespace std;

int main()
{
    int numGames, numWins;
    cin >> numGames >> numWins;

    int winPercent = (long long) 100 * numWins / numGames;

    if (winPercent >= 99)
    {
        cout << -1;
        return 0;
    }

    int l = 0;
    int r = numGames;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if ((long long) 100 * (numWins + m) / (numGames + m) > winPercent)
            r = m - 1;
        else
            l = m + 1;
    }

    cout << l;
    return 0;
}