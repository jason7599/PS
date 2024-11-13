#include <iostream>
#include <queue>

const int max_pos = 1e6;

// {min_time, num_paths}
std::pair<int, int> solve(int start, int dest)
{
    static int path_cnt[max_pos + 1] = {0};
    static int visited[max_pos + 1] = {0};
    std::queue<int> q;

    path_cnt[start] = 1;
    q.push(start);

    int time = 0;
    int q_size;
    while ((q_size = q.size()) && !path_cnt[dest])
    {
        while (q_size--)
        {
            int pos = q.front();
            q.pop();
            
            int moves[] = {pos - 1, pos + 1, pos * 2};

            for (int npos : moves)
            {
                if (0 <= npos && npos <= max_pos)
                {
                    if (!visited[npos])
                    {
                        visited[npos] = time + 1;
                        path_cnt[npos] = path_cnt[pos];
                        q.push(npos);
                    }
                    else if (visited[npos] == time + 1)
                        path_cnt[npos] += path_cnt[pos];
                }
            }
        }

        time++;
    }

    return {time, path_cnt[dest]};
}

int main()
{
    int start, dest;
    std::cin >> start >> dest;
    auto [min_time, num_paths] = solve(start, dest);
    std::cout << min_time << '\n' << num_paths;
}