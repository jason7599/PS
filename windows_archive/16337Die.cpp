#include <iostream>

using namespace std;

const char DENT_SURFACE = 'o';
const char SMOOTH_SURFACE = ':';

int determineDiceNumber(const char diceImage[3][3])
{
	if (diceImage[0][0] == SMOOTH_SURFACE && diceImage[0][1] == SMOOTH_SURFACE && diceImage[0][2] == SMOOTH_SURFACE && diceImage[1][0] == SMOOTH_SURFACE && diceImage[1][1] == DENT_SURFACE && diceImage[1][2] == SMOOTH_SURFACE && diceImage[2][0] == SMOOTH_SURFACE && diceImage[2][1] == SMOOTH_SURFACE && diceImage[2][2] == SMOOTH_SURFACE)
	{
		return 1;
	}
	else if ((diceImage[0][0] == DENT_SURFACE && diceImage[0][1] == SMOOTH_SURFACE && diceImage[0][2] == SMOOTH_SURFACE && diceImage[1][0] == SMOOTH_SURFACE && diceImage[1][1] == SMOOTH_SURFACE && diceImage[1][2] == SMOOTH_SURFACE && diceImage[2][0] == SMOOTH_SURFACE && diceImage[2][1] == SMOOTH_SURFACE && diceImage[2][2] == DENT_SURFACE) || (diceImage[0][0] == SMOOTH_SURFACE && diceImage[0][1] == SMOOTH_SURFACE && diceImage[0][2] == DENT_SURFACE && diceImage[1][0] == SMOOTH_SURFACE && diceImage[1][1] == SMOOTH_SURFACE && diceImage[1][2] == SMOOTH_SURFACE && diceImage[2][0] == DENT_SURFACE && diceImage[2][1] == SMOOTH_SURFACE && diceImage[2][2] == SMOOTH_SURFACE))
	{
		return 2;
	}
	else if ((diceImage[0][0] == DENT_SURFACE && diceImage[0][1] == SMOOTH_SURFACE && diceImage[0][2] == SMOOTH_SURFACE && diceImage[1][0] == SMOOTH_SURFACE && diceImage[1][1] == DENT_SURFACE && diceImage[1][2] == SMOOTH_SURFACE && diceImage[2][0] == SMOOTH_SURFACE && diceImage[2][1] == SMOOTH_SURFACE && diceImage[2][2] == DENT_SURFACE) || (diceImage[0][0] == SMOOTH_SURFACE && diceImage[0][1] == SMOOTH_SURFACE && diceImage[0][2] == DENT_SURFACE && diceImage[1][0] == SMOOTH_SURFACE && diceImage[1][1] == DENT_SURFACE && diceImage[1][2] == SMOOTH_SURFACE && diceImage[2][0] == DENT_SURFACE && diceImage[2][1] == SMOOTH_SURFACE && diceImage[2][2] == SMOOTH_SURFACE))
	{
		return 3;
	}
	else if (diceImage[0][0] == DENT_SURFACE && diceImage[0][1] == SMOOTH_SURFACE && diceImage[0][2] == DENT_SURFACE && diceImage[1][0] == SMOOTH_SURFACE && diceImage[1][1] == SMOOTH_SURFACE && diceImage[1][2] == SMOOTH_SURFACE && diceImage[2][0] == DENT_SURFACE && diceImage[2][1] == SMOOTH_SURFACE && diceImage[2][2] == DENT_SURFACE)
	{
		return 4;
	}
	else if (diceImage[0][0] == DENT_SURFACE && diceImage[0][1] == SMOOTH_SURFACE && diceImage[0][2] == DENT_SURFACE && diceImage[1][0] == SMOOTH_SURFACE && diceImage[1][1] == DENT_SURFACE && diceImage[1][2] == SMOOTH_SURFACE && diceImage[2][0] == DENT_SURFACE && diceImage[2][1] == SMOOTH_SURFACE && diceImage[2][2] == DENT_SURFACE)
	{
		return 5;
	}
	else if ((diceImage[0][0] == DENT_SURFACE && diceImage[0][1] == DENT_SURFACE && diceImage[0][2] == DENT_SURFACE && diceImage[1][0] == SMOOTH_SURFACE && diceImage[1][1] == SMOOTH_SURFACE && diceImage[1][2] == SMOOTH_SURFACE && diceImage[2][0] == DENT_SURFACE && diceImage[2][1] == DENT_SURFACE && diceImage[2][2] == DENT_SURFACE) || (diceImage[0][0] == DENT_SURFACE && diceImage[0][1] == SMOOTH_SURFACE && diceImage[0][2] == DENT_SURFACE && diceImage[1][0] == DENT_SURFACE && diceImage[1][1] == SMOOTH_SURFACE && diceImage[1][2] == DENT_SURFACE && diceImage[2][0] == DENT_SURFACE && diceImage[2][1] == SMOOTH_SURFACE && diceImage[2][2] == DENT_SURFACE))
	{
		return 6;
	}
    else
    {
        return -1;
    }
}

int main()
{
    char diceImage[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> diceImage[i][j];
        }
    }

    int diceNumber = determineDiceNumber(diceImage);

    if (diceNumber == -1)
    {
        cout << "unknown";
    }
    else
    {
        cout << diceNumber;
    }

    return 0;
}