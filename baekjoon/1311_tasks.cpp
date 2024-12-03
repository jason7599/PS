#include <iostream>
#include <algorithm>

int n_tasks;
int task_costs[20][20]; // [person][task]

int solve(int person_idx, int tasks_done)
{
    static int memo[20][1 << 20];

    if (person_idx == n_tasks)
        return 0;
    
    if (memo[person_idx][tasks_done])
        return memo[person_idx][tasks_done];
    
    int min_cost = 1e9;
    for (int t = 0; t < n_tasks; t++)
    {
        if (!(tasks_done & (1 << t)))
        {
            int cost = task_costs[person_idx][t]
                + solve(person_idx + 1, tasks_done | (1 << t));
            
            min_cost = std::min(min_cost, cost);
        }
    }

    return memo[person_idx][tasks_done] = min_cost;
}

int main()
{
    std::cin >> n_tasks;
    for (int p = 0; p < n_tasks; p++)
    {
        for (int t = 0; t < n_tasks; t++)
            std::cin >> task_costs[p][t];
    }

    std::cout << solve(0, 0);
}