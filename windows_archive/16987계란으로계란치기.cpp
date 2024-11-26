#include <iostream>

using namespace std;

struct Egg
{
    int durability;
    int weight;

    bool isBroken()
    {
        return durability <= 0;
    }
};

int numEggs;
Egg eggs[8];
int maxBrokenEggs;

// backtracking
void solve(int eggIndex = 0)
{
    static int numBrokenEggs;

    if (eggIndex == numEggs || numBrokenEggs == numEggs - 1)
    {
        if (numBrokenEggs > maxBrokenEggs)
            maxBrokenEggs = numBrokenEggs;
        return;
    }

    Egg& thisEgg = eggs[eggIndex];

    if (thisEgg.isBroken())
        return solve(eggIndex + 1);

    for (int otherEggIndex = 0; otherEggIndex < numEggs; otherEggIndex++)
    {
        if (eggIndex == otherEggIndex)
            continue;

        Egg& otherEgg = eggs[otherEggIndex];

        if (otherEgg.isBroken())
            continue;
        
        thisEgg.durability -= otherEgg.weight;
        otherEgg.durability -= thisEgg.weight;

        bool thisFlag, otherFlag;
        
        if ((thisFlag = thisEgg.isBroken()))
            numBrokenEggs++;
        if ((otherFlag = otherEgg.isBroken()))
            numBrokenEggs++;

        solve(eggIndex + 1);

        thisEgg.durability += otherEgg.weight;
        otherEgg.durability += thisEgg.weight;

        if (thisFlag)
            numBrokenEggs--;
        if (otherFlag)
            numBrokenEggs--;
    }
}

int main()
{
    cin >> numEggs;
    
    for (int i = 0; i < numEggs; i++)
    {
        int durability, weight;
        cin >> durability >> weight;
        eggs[i] = Egg{durability, weight};
    }

    solve();

    cout << maxBrokenEggs;

    return 0;
}