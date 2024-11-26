#include <iostream>
#include <cmath>

using namespace std;

int length;
char boj[1'000];

int getMinCost(int index)
{
    static int dp[1'000];

    if (index == length - 1)
        return 0;

    if (dp[index])
        return dp[index];

    char next;
    switch (boj[index])
    {
        case 'B': next = 'O'; break;
        case 'O': next = 'J'; break;
        case 'J': next = 'B'; break;
    }

    int minCost = -1; // -1 = inf

    for (int nextIndex = index + 1; nextIndex < length; nextIndex++)
    {
        if (boj[nextIndex] == next)
        {
            int nextCost = getMinCost(nextIndex);
            if (nextCost == -1)
                continue;
            
            int cost = pow(nextIndex - index, 2) + nextCost;
            if (minCost == -1 || cost < minCost)
                minCost = cost;
        }
    }

    return dp[index] = minCost;
}

int main()
{
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> boj[i];
    }

    cout << getMinCost(0);
}