#include <bits/stdc++.h>

int n_students;
int wants[100'001];
int visited[100'001];
int n_team_members;

const int M_CYCLE = -1;

void dfs(int idx, int s_num)
{
    visited[idx] = s_num;

    int n_idx = wants[idx];
    if (visited[n_idx] == s_num) // cycle
    {
        visited[idx] = M_CYCLE;
        n_team_members++;
        
        for (; n_idx != idx; n_idx = wants[n_idx])
        {
            visited[n_idx] = M_CYCLE;
            n_team_members++;
        }   
    }
    else if (!visited[n_idx])
        dfs(n_idx, s_num);
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_tc;
    std::cin >> n_tc;

    while (n_tc--)
    {
        std::cin >> n_students;

        n_team_members = 0;

        for (int s_num = 1; s_num <= n_students; s_num++)
        {
            std::cin >> wants[s_num];
            visited[s_num] = 0;
        }

        for (int idx = 1; idx <= n_students; idx++)
        {
            if (!visited[idx])
                dfs(idx, idx);
        }

        std::cout << n_students - n_team_members << '\n';
    }
}