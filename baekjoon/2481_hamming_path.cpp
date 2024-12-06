#include <iostream>
#include <queue>
#include <map>

const int MAX_N_CODES = 1e5;

int n_codes, n_bits;
std::vector<int> adj_list[MAX_N_CODES + 1];

int prev[MAX_N_CODES + 1]; // 0 for unvisited

void bfs()
{
    std::queue<int> q({1});
    prev[1] = -1; // visited check 

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int adj : adj_list[x])
        {
            if (!prev[adj])
            {
                prev[adj] = x;
                q.push(adj);
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> n_codes >> n_bits;

    std::map<int, int> vals_idxs;

    for (int i = 1; i <= n_codes; i++)
    {
        int val = 0;
        for (int j = 0; j < n_bits; j++)
        {
            char c;
            std::cin >> c;
            val = val * 2 + (c == '1');
        }

        vals_idxs[val] = i;
    }

    for (const auto& [val, idx] : vals_idxs)
    {
        for (int b = 0; b < n_bits; b++)
        {
            int nval = val ^ (1 << b);
            if (vals_idxs.count(nval))
                adj_list[idx].push_back(vals_idxs.at(nval));
        }
    }

    bfs();

    int n_queries;
    std::cin >> n_queries;

    while (n_queries--)
    {
        int dest_idx;
        std::cin >> dest_idx;

        if (prev[dest_idx])
        {
            std::vector<int> path;
            int t = dest_idx;
            while (t != -1)
            {
                path.push_back(t);
                t = prev[t];
            }

            size_t i = path.size();
            while (i--)
                std::cout << path[i] << ' ';
            std::cout << '\n';
        }
        else
            std::cout << -1 << '\n';
    }
}