#include <iostream>

using namespace std;

int main()
{
    int blocks[1000];
    int numBlocks;
    int targetDiff;

    cin >> numBlocks >> targetDiff;
    for (int i = 0; i < numBlocks; i++)
        cin >> blocks[i];

    int bestTime = 1000;
    for (int i = 0; i < numBlocks; i++)
    {
        int pivot = blocks[i];
        if (pivot - i * targetDiff <= 0)
            continue;
        
        int time = 0;
        for (int j = -i; j < numBlocks - i; j++)
        {
            if (blocks[i + j] != pivot + j * targetDiff)
                time++;
        }

        // cout << i << ": " << time << '\n';

        if (time < bestTime)
        {
            if ((bestTime = time) == 0)
                break;
        }
    }

    cout << bestTime;

    return 0;
}