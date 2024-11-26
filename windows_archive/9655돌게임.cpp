#include <iostream>

using namespace std;

int main()
{
    int numberOfStonesOnTheTable;
    cin >> numberOfStonesOnTheTable;

    bool theGuyWhoGoesFirstWins[1001];
    theGuyWhoGoesFirstWins[1] = true;
    theGuyWhoGoesFirstWins[2] = false;
    theGuyWhoGoesFirstWins[3] = true;

    for (int i = 4; i <= numberOfStonesOnTheTable; i++)
    {
        theGuyWhoGoesFirstWins[i] = !theGuyWhoGoesFirstWins[i - 1] || !theGuyWhoGoesFirstWins[i - 3];
    }

    if (theGuyWhoGoesFirstWins[numberOfStonesOnTheTable])
        cout << "SK";
    else
        cout << "CY";
    
    return 0;
}