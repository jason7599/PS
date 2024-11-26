#include <iostream>
#include <queue>

using namespace std;

int solve(int target)
{
    static bool visited[1001][1001]; // cur, clipboard
    queue<pair<int,int>> q;

    visited[1][0] = true;
    q.push({1, 0});

    int time = 0;
    int q_size;
    while ((q_size = q.size()))
    {
        while (q_size--)
        {
            int cur = q.front().first;
            int clip = q.front().second;
            q.pop();

            if (cur == target)
                return time;
            
            if (clip && cur + clip <= target && !visited[cur + clip][clip]) // paste
            {
                visited[cur + clip][clip] = true;
                q.push({cur + clip, clip});
            }

            if (!visited[cur][cur]) // copy
            {
                visited[cur][cur] = true;
                q.push({cur, cur});
            }

            if (cur && !visited[cur - 1][clip]) // delete
            {
                visited[cur - 1][clip] = true;
                q.push({cur - 1, clip});
            }
        }

        time++;
    }

    return -1239174612;
}

int main()
{
    int target; cin >> target;
    cout << solve(target);
}