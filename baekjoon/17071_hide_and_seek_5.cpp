#include <bits/stdc++.h>

const int MAX_POS = 500'000;

bool visited[MAX_POS + 1];

int solve(int init_start, int init_dest)
{
    std::queue<int> q({init_start});
    visited[init_start] = 1;

    int dest_pos = init_dest;
    for (int q_size, time = 0; (q_size = q.size()); time++)
    {
        dest_pos += time;
        while (q_size--)
        {
            int pos = q.front();
            q.pop();

            if (pos == dest_pos)
                return time;

            int nx_poss[] = {pos - 1, pos + 1, pos * 2};

            for (int nx_pos : nx_poss)
            {
                if (0 <= nx_pos && nx_pos <= MAX_POS && !visited[nx_pos])
                {
                    visited[nx_pos] = 1;
                    q.push(nx_pos);
                }
            }
        }
    }

    return -1;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int init_start, init_dest;
    std::cin >> init_start >> init_dest;

    std::cout << solve(init_start, init_dest) << '\n';
}