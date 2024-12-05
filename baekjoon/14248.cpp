#include <iostream>
#include <queue>

int n_stones, jump[100'000];
bool visited[100'000];

int solve(int start)
{
    std::queue<int> q({start});
    visited[start] = 1;
    int ans = 0;

    while (!q.empty())
    {
        int pos = q.front();
        q.pop();

        ans++;

        for (int d = -1; d <= 1; d += 2)
        {
            int npos = pos + jump[pos] * d;
            if (npos >= 0 && npos < n_stones && !visited[npos])
            {
                visited[npos] = 1;
                q.push(npos);
            }
        }
    }

    return ans;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> n_stones;
    for (int i = 0; i < n_stones; i++)
        std::cin >> jump[i];
    
    int start;
    std::cin >> start;
    
    std::cout << solve(--start);
}