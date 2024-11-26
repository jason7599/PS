#include <iostream>

using namespace std;

bool isBadCombination[201][201];

int main()
{
    int numIcecreams, numBadCombinations;
    cin >> numIcecreams >> numBadCombinations;

    while (numBadCombinations--)
    {
        int ic0, ic1;
        cin >> ic0 >> ic1;
        isBadCombination[ic0][ic1] = true;
        isBadCombination[ic1][ic0] = true;
    }

    int numPossibleCombinations = 0;
    for (int ic0 = 1; ic0 <= numIcecreams - 2; ic0++)
    {
        for (int ic1 = ic0 + 1; ic1 <= numIcecreams - 1; ic1++)
        {
            for (int ic2 = ic1 + 1; ic2 <= numIcecreams; ic2++)
            {
                if (!isBadCombination[ic0][ic1] && !isBadCombination[ic1][ic2] && !isBadCombination[ic0][ic2])
                {
                    numPossibleCombinations++;
                }
            }
        }
    }

    cout << numPossibleCombinations;
}