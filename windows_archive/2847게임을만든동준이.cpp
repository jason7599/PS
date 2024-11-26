#include <iostream>

using namespace std;

int main()
{
    int num_levels, level_scores[100];

    cin >> num_levels;
    for (int i = 0; i < num_levels; i++)
        cin >> level_scores[i];
    
    int modify_ammount = 0;
    for (int level = num_levels - 2; level >= 0; level--)
    {
        int next_level_score = level_scores[level + 1];
        if (level_scores[level] >= next_level_score)
        {
            modify_ammount += level_scores[level] - next_level_score + 1;
            level_scores[level] = next_level_score - 1;
        }
    }

    cout << modify_ammount;
}