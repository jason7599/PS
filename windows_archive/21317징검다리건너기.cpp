#include <iostream>
#include <algorithm>

using namespace std;

struct Stone
{
    int smallJumpCost;
    int bigJumpCost;
};

Stone stones[20];
int numStones;
int omegaJumpCost;

int calculateMinimumAmountOfEnergyRequiredToGetToTheLastStone(int stoneIndex, bool alreadyUsedOmegaJump)
{
    static int memoOfMinimumAmountOfEnergyRequiredToGetToTheLastStone[20][2];

    if (stoneIndex == numStones - 1)
        return 0;
    
    if (stoneIndex > numStones - 1)
        return 1e9;
    
    if (memoOfMinimumAmountOfEnergyRequiredToGetToTheLastStone[stoneIndex][alreadyUsedOmegaJump])
        return memoOfMinimumAmountOfEnergyRequiredToGetToTheLastStone[stoneIndex][alreadyUsedOmegaJump];

    int minimumAmountOfEnergyRequiredToGetToTheLastStone = 1e9;

    if (!alreadyUsedOmegaJump)
        minimumAmountOfEnergyRequiredToGetToTheLastStone = omegaJumpCost + calculateMinimumAmountOfEnergyRequiredToGetToTheLastStone(stoneIndex + 3, 1);

    minimumAmountOfEnergyRequiredToGetToTheLastStone = min({
        minimumAmountOfEnergyRequiredToGetToTheLastStone, 
        stones[stoneIndex].smallJumpCost + calculateMinimumAmountOfEnergyRequiredToGetToTheLastStone(stoneIndex + 1, alreadyUsedOmegaJump),
        stones[stoneIndex].bigJumpCost + calculateMinimumAmountOfEnergyRequiredToGetToTheLastStone(stoneIndex + 2, alreadyUsedOmegaJump)
    });

    return memoOfMinimumAmountOfEnergyRequiredToGetToTheLastStone[stoneIndex][alreadyUsedOmegaJump] = minimumAmountOfEnergyRequiredToGetToTheLastStone;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> numStones;
    for (int i = 0; i < numStones - 1; i++)
    {
        cin >> stones[i].smallJumpCost;
        cin >> stones[i].bigJumpCost;
    }
    cin >> omegaJumpCost;

    cout << calculateMinimumAmountOfEnergyRequiredToGetToTheLastStone(0, 0);
    return 0;
}