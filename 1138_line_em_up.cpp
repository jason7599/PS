#include <iostream>
#include <algorithm>

/**
 * N people lining up.
 * People only remember how many others on their left were taller.
 * Every person has different height.
 * 
 * ... backtracking?... i mean we have 2 seconds and # of people at max 10
 */

int main()
{
    int n_people;
    int info[11]; // info[x]: how many others on their left is taller
    int ans[10];

    std::cin >> n_people;

    for (int p = 1; p <= n_people; p++)
    {
        std::cin >> info[p];
        ans[p - 1] = p;
    }

    while (1)
    {
        bool nope = 0;

        for (int i = 0; i < n_people; i++)
        {
            int t = 0;
            for (int j = 0; j < i; j++)
            {
                if (ans[j] > ans[i])
                    t++;
            }

            if (t != info[ans[i]])
            {
                nope = 1;
                break;
            }
        }

        if (!nope)
            break;

        std::next_permutation(ans, ans + n_people);
    }
    
    for (int p = 0; p < n_people; p++)
        std::cout << ans[p] << ' ';
}