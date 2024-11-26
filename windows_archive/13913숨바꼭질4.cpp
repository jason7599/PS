#include <iostream>
#include <queue>

#define MAX 100'001

using namespace std;

bool visited[MAX];
int start, dest, prv[MAX];

int bfs()
{
    queue<int> q;
    visited[start] = true;
    q.push(start);

    int time = 0;
    int qSize = 1;

    while (qSize)
    {
        qSize = q.size();
        while (qSize--)
        {
            int cur = q.front();
            q.pop();

            if (cur == dest) return time;

            for (int i = 0; i < 3; i++)
            {
                int next = cur;
                if (i == 0) next++;
                else if (i == 1) next--;
                else if (i == 2) next *= 2;

                if (next < 0 || next >= MAX || visited[next])
                    continue;
                
                visited[next] = true;
                prv[next] = cur;
                q.push(next);
            }
        }
        time++;
    }
}

void backtrack(int x)
{
    if (x != start)
        backtrack(prv[x]);
    cout << x << ' ';
}

int main()
{
    cin >> start >> dest;

    cout << bfs() << '\n';
    backtrack(dest);

}