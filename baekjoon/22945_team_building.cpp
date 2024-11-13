#include <iostream>
#include <algorithm>

using namespace std;

int skills[100'001];

int get_skills(int dev0, int dev1)
{
    return (dev1 - dev0 + 1) * min(skills[dev0], skills[dev1]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int num_devs;
    cin >> num_devs;
    for (int i = 0; i < num_devs; i++)
        cin >> skills[i];

    int max_skill = 0;

    int l = 0;
    int r = num_devs - 1;
    while (l < r)
    {
        max_skill = max(max_skill,
            (r - l - 1) * min(skills[l], skills[r]));
        
        if (skills[l] < skills[r])
            l++;
        else
            r--;
    }

    cout << max_skill;
    return 0;
}