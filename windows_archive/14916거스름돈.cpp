#include <iostream>
#include <algorithm>

#define INF 987654321

using namespace std;

int memo[100'001];

int minCoins(int change)
{
    if (change < 0) return INF;
    if (!change) return 0;

    int& res = memo[change];
    if (res) return res;

    int minCoins2 = minCoins(change - 2);
    int minCoins5 = minCoins(change - 5);

    if (minCoins2 == INF && minCoins5 == INF)
        return res = INF;

    return res = min(minCoins2, minCoins5) + 1;
}

int main()
{
    int change;
    cin >> change;

    int res = minCoins(change);
    cout << (res == INF ? -1 : res);
}