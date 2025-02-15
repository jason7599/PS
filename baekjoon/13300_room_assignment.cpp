#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_students, max_capacity;
    std::cin >> n_students >> max_capacity;

    std::vector<std::vector<int>> assigned(2, std::vector<int>(6));

    int n_rooms = 0;
    while (n_students--)
    {
        int gender, grade;
        std::cin >> gender >> grade;

        int& pop = assigned[gender][--grade];
        
        if (!pop++)
            n_rooms++;
        else if (pop == max_capacity)
            pop = 0;
    }

    std::cout << n_rooms << '\n';
}