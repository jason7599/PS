#include <iostream>
#include <algorithm>

using namespace std;

int num_lines;
int cur_indents[1000];
int des_indents[1000];

int fix(int line)
{
    int delta = des_indents[line] - cur_indents[line];

    if (!delta)
        return 0;

    int best_stop = line;
    int max_save = abs(delta);

    for (int stop = line + 1; stop < num_lines; stop++)
    {
        
    }

    return cost;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> num_lines;
    for (int i = 0; i < num_lines; i++)
        cin >> cur_indents[i];
    for (int i = 0; i < num_lines; i++)
        cin >> des_indents[i];

    

    return 0;
}