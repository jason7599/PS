#include <iostream>

using namespace std;

bool road_dirty[(int)1e6];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int road_len, num_commands;
    cin >> road_len >> num_commands;

    int num_dirty_streaks = 0;

    for (int i = 0; i < road_len; i++)
    {
        cin >> road_dirty[i];

        if (road_dirty[i])
        {
            if (!i || !road_dirty[i - 1])
                num_dirty_streaks++;
        }
    }

    while (num_commands--)
    {
        int command;
        cin >> command;

        if (command == 0)
            cout << num_dirty_streaks << '\n';
        else
        {
            int road_index;
            cin >> road_index;
            road_index--;

            if (road_dirty[road_index])
                continue;
            
            road_dirty[road_index] = 1;

            // 2 streaks merge into 1
            if (road_index && road_index + 1 != road_len 
                && road_dirty[road_index - 1] && road_dirty[road_index + 1])
                num_dirty_streaks--;

            if ((!road_index || !road_dirty[road_index - 1])
                && (road_index + 1 == road_len || !road_dirty[road_index + 1]))
                num_dirty_streaks++;
        }
    }

    return 0;
}