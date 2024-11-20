#include <iostream>
#include <queue>

std::vector<int> edges[50];

int solve(int node)
{
    if (edges[node].empty())
        return 0;

    // longest first
    std::priority_queue<int> pq;
    for (int chd : edges[node])
        pq.push(1 + solve(chd));
    
    int res = 0;
    int t = 0; // elapsed
    while (!pq.empty())
    {
        res = std::max(res, pq.top() + t++);
        pq.pop();
    }
    return res;
}

int main()
{
    int n_nodes;
    std::cin >> n_nodes;
    
    for (int i = 0; i < n_nodes; i++)
    {
        int b;
        std::cin >> b;
        if (i)
            edges[b].push_back(i);
    }

    std::cout << solve(0);
}