#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int numCoins;
    cin >> numCoins;

    int coins[1000];
    for (int i = 0; i < numCoins; i++)
        cin >> coins[i];

    sort(coins, coins + numCoins);

    int nextVal = 1;

    
}