#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int max_val;
    std::cin >> max_val;

    std::vector<bool> visited(max_val + 1);

    int n_init;
    std::cin >> n_init;

    std::queue<int> q;

    while (n_init--)
    {
        int val;
        std::cin >> val;

        q.push(val);
        visited[val] = 1;
    }

    int dist = 0;
    for (int q_size; (q_size = q.size()); dist++)
    {
        while (q_size--)
        {
            int val = q.front();
            q.pop();

            for (int bi = 0; bi < 20; bi++)
            {
                int next = val ^ (1 << bi);
                
                if (next <= max_val && !visited[next])
                {
                    visited[next] = 1;
                    q.push(next);
                }
            }
        }
    }

    std::cout << dist - 1 << '\n';
}