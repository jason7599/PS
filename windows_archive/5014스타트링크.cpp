#include <iostream>
#include <queue>

using namespace std;

bool visited[1'000'001];

int minPresses(int maxFloor, int currentFloor, int targetFloor,  int upDelta, int downDelta)
{
    queue<int> q;
    q.push(currentFloor);
    visited[currentFloor] = true;

    int res = 0;

    while (int qSize = q.size())
    {
        for (int i = 0; i < qSize; i++)
        {
            int floor = q.front();
            q.pop();

            if (floor == targetFloor) return res;

            if (floor + upDelta <= maxFloor && ! visited[floor + upDelta]) 
            {
                q.push(floor + upDelta);
                visited[floor + upDelta] = true;
            }
            if (floor - downDelta > 0 && ! visited[floor - downDelta])
            {
                q.push(floor - downDelta);
                visited[floor - downDelta] = true;
            }
        }
        res++;
    }

    return -1;

}

int main()
{
    int maxFloor, currentFloor, targetFloor, upDelta, downDelta;
    cin >> maxFloor >>  currentFloor >> targetFloor >> upDelta >> downDelta;

    int res = minPresses(maxFloor, currentFloor, targetFloor, upDelta, downDelta);
    if (res == -1) cout << "use the stairs"; else cout << res;
}