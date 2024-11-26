#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int str_len;
    cin >> str_len;

    int num_h = 0;
    int num_y = 0;
    int num_u = 0;

    vector<int> fucks;
    int fuck = 0;

    for (int i = 0; i < str_len; i++)
    {
        char c;
        cin >> c;

        if (c == 'H' || c == 'Y' || c == 'U')
        {
            if (fuck != 0)
            {
                fucks.push_back(fuck);
                fuck = 0;
            }
            if (c == 'H')
                num_h++;
            else if (c == 'Y')
                num_y++;
            else
                num_u++;
        }
        else
            fuck++;
    }

    if (fuck != 0)
        fucks.push_back(fuck);

    int del_cost, drag_cost;
    cin >> del_cost >> drag_cost;

    int cost = 0;
    for (int fuck : fucks)
        cost += min(fuck * del_cost, drag_cost + del_cost);
    
    if (cost != 0)
        cout << cost;
    else
        cout << "Nalmeok";
    cout << '\n';

    int hyu = min(num_h, min(num_y, num_u));
    if (hyu != 0)
        cout << hyu;
    else
        cout << "I love HanYang University";

    return 0;
}