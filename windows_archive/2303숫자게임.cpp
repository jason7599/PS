#include <iostream>

using namespace std;

int getBestScore(int cards[5])
{
    int i, j;
    int sum = 0;
    int score;
    int bestScore = 0;

    for (i = 0; i < 5; i++)
        sum += cards[i];

    for (i = 0; i < 4; i++)
    {
        sum -= cards[i];

        for (j = i + 1; j < 5; j++)
        {
            sum -= cards[j];
            score = sum % 10;

            if (score > bestScore)
                bestScore = score;

            sum += cards[j];
        }

        sum += cards[i];
    }

    return bestScore;
}

int main() 
{
    int playerCount;
    int bestScore = 0;
    int score;
    int winner;
    int cards[5];
    int i, c;

    cin >> playerCount;
    for (i = 1; i <= playerCount; i++)
    {   
        for (c = 0; c < 5; c++)
            cin >> cards[c];

        score = getBestScore(cards);
        if (score >= bestScore)
        {
            bestScore = score;
            winner = i;
        }
    }

    cout << winner;
}