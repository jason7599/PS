#include <iostream>
#include <queue>

using namespace std;

int root[10'001];
int find_root(int x)
{
    if (x != root[x])
        root[x] = find_root(root[x]);
    return root[x];
}

int main()
{
    int num_vertices, num_edges;
    cin >> num_vertices >> num_edges;

    priority_queue<pair<int,pair<int,int>>> edges;

    for (int i = 0; i < num_edges; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        edges.push({-weight, {from, to}});
    }

    int min_edge_weight = 0;

    for (int i = 1; i <= num_vertices; i++)
        root[i] = i;
    
    while (!edges.empty())
    {
        int from = edges.top().second.first;
        int to = edges.top().second.second;
        int weight = -edges.top().first;
        edges.pop();

        from = find_root(from);
        to = find_root(to);

        if (from == to) continue; // unsafe edge

        if (from < to) root[to] = from;
        else root[from] = to;

        min_edge_weight += weight;
    }

    cout << min_edge_weight;
}