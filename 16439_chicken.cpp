#include <iostream>
#include <algorithm>
#include <vector>

int num_members, num_chickens;
int preference[30][30];

int calc_satisfaction(const std::vector<int>& chickens)
{
    int satisfaction = 0;
    for (int m = 0; m < num_members; m++)
    {
        int t = 0;
        for (int c : chickens)
            t = std::max(t, preference[m][c]);
        satisfaction += t;
    }
    return satisfaction;
}

int solve(int c_idx = 0)
{
    static std::vector<int> chickens;

    if (chickens.size() == 3)
        return calc_satisfaction(chickens);
    
    if (c_idx == num_chickens)
        return 0;
    
    int res = 0;
    for (; c_idx < num_chickens; c_idx++)
    {
        chickens.push_back(c_idx);
        res = std::max(res, solve(c_idx + 1));
        chickens.pop_back();
    }

    return res;
}

int main()
{
    std::cin >> num_members >> num_chickens;

    for (int m = 0; m < num_members; m++)
    {
        for (int c = 0; c < num_chickens; c++)
            std::cin >> preference[m][c];
    }

    std::cout << solve();
}