#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numNodes, numEdges;
int root[200'000]; // union find

int findRoot(int node)
{
    if (root[node] != node)
        root[node] = findRoot(root[node]);
    return root[node];
}

void linkNodes(int node0, int node1)
{
    int root0 = findRoot(node0);
    int root1 = findRoot(node1);

    if (root0 < root1)
        root[root1] = root0;
    else
        root[root0] = root1; 
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while (true)
    {
        cin >> numNodes >> numEdges;

        if (numNodes == 0 && numEdges == 0)
            break;
        
        for (int i = 0; i < numNodes; i++)
            root[i] = i;

        int totalCost = 0;
        // <dist, <node0, node1>>
        vector<pair<int, pair<int, int>>> edges;

        for (int i = 0; i < numEdges; i++)
        {
            int node0, node1, dist;
            cin >> node0 >> node1 >> dist;

            edges.push_back({dist, {node0, node1}});
            totalCost += dist;
        }

        sort(edges.begin(), edges.end());

        int savedCost = 0;

        for (auto edge : edges)
        {
            int dist = edge.first;
            int node0 = edge.second.first;
            int node1 = edge.second.second;

            if (findRoot(node0) != findRoot(node1))
            {
                linkNodes(node0, node1);
                savedCost += dist;
            }
        }

        cout << totalCost - savedCost << '\n';
    }

    return 0;
}