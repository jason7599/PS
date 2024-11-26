#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define MAX_NODE_COUNT 1000

struct edge
{
    int to;
    int dist;
};

vector<edge> edges[MAX_NODE_COUNT + 1];

int distance_between(int node0, int node1)
{
    struct trav { int cur, prev, dist; };
    stack<trav> stack;

    stack.push({node0, 0, 0});
    while (!stack.empty())
    {
        trav trav = stack.top();
        stack.pop();

        for (edge e : edges[trav.cur])
        {
            if (e.to == trav.prev)
                continue;
            
            if (e.to == node1)
                return trav.dist + e.dist;
            
            stack.push({e.to, trav.cur, trav.dist + e.dist});
        }
    }

    return -1;
}

int main()
{
    int num_nodes, num_queries;
    cin >> num_nodes >> num_queries;

    for (int i = 0; i < num_nodes - 1; i++)
    {
        int from, to, dist;
        cin >> from >> to >> dist;

        edges[from].push_back({to, dist});
        edges[to].push_back({from, dist});
    }

    for (int i = 0; i < num_queries; i++)
    {
        int node0, node1;
        cin >> node0 >> node1;
        cout << distance_between(node0, node1) << '\n';
    }
}