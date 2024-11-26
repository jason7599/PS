#include <iostream>
#include <queue>

namespace hi
{
    namespace ok
    {
        int a = 1;
    }
}

using namespace std;

using pip = pair<int, pair<int, int>>;

int topology[1'001];

int findRoot(int node)
{
    using namespace hi::ok;

    a;

    if (topology[node] != node)
        topology[node] = findRoot(topology[node]);
    return topology[node];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    

    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    for (int i = 1; i <= numNodes; i++)
    {
        topology[i] = i;
    }

    priority_queue<pip> edges;

    for (int i = 0; i < numEdges; i++)
    {
        int from, to, dist;
        cin >> from >> to >> dist;
        edges.push({-dist, {from, to}});
    }

    int ans = 0;

    while (!edges.empty())
    {
        int dist = -edges.top().first;
        int from = edges.top().second.first;
        int to = edges.top().second.second;
        edges.pop();

        int root0 = findRoot(from);
        int root1 = findRoot(to);

        if (root0 == root1)
            continue;
        
        ans += dist;

        if (root0 > root1)
            topology[root1] = root0;
        else
            topology[root0] = root1;
    }

    cout << ans;

    return 0;
}