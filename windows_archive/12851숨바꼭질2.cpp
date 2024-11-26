#include <iostream>
#include <queue>

using namespace std;

const int max_pos = 100'001;

pair<int,int> solve(int start, int finish)
{
    static int visited_time[max_pos];
    static int path_count[max_pos];
    queue<int> q;
    
    q.push(start);
    path_count[start] = 1;
    
    int time = 0;
    int q_size;
    while ((q_size = q.size()))
    {
        while (q_size--)
        {
            int pos = q.front();
            q.pop();

            if (pos == finish)
                return {time, path_count[finish]};

            if (pos + 1 < max_pos)
            {
                if (!visited_time[pos + 1])
                {
                    visited_time[pos + 1] = time;
                    path_count[pos + 1] = path_count[pos];
                    q.push(pos + 1);
                }
            }
        }

        time++;
    }
}

int main()
{
    int start, finish;
    cin >> start >> finish;
}