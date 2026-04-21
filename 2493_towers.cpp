#include <bits/stdc++.h>

struct Tower
{
    int num;
    int height;
};

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_towers;
    std::cin >> n_towers;

    std::stack<Tower> visible_towers;

    for (int townum = 1; townum <= n_towers; townum++)
    {
        int height;
        std::cin >> height;

        while (!visible_towers.empty()
            && visible_towers.top().height <= height)
            visible_towers.pop();
        
        std::cout << (visible_towers.empty() ? 0 : visible_towers.top().num) << ' ';

        visible_towers.push(Tower{townum, height});
    }

    std::cout << '\n';
}