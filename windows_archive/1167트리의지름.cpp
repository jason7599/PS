#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
    int dest;
    int dist;
};

vector<Edge> edges[100'001];

pair<int,int> get_furthest_node_and_dist(int from_node, int prev_node = 0)
{
    int max_dist = 0;
    int max_dist_node = from_node;

    for (Edge edge : edges[from_node])
    {
        if (edge.dest == prev_node)
            continue;
        
        pair<int, int> nnd = get_furthest_node_and_dist(edge.dest, from_node);
        int dist = edge.dist + nnd.second;
        if (dist > max_dist)
        {
            max_dist = dist;
            max_dist_node = nnd.first;
        }
    }

    return {max_dist_node, max_dist};
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int num_nodes; cin >> num_nodes;
    for (int i = 0; i < num_nodes; i++)
    {
        int node; cin >> node;
        while (true)
        {
            int dest; cin >> dest;
            if (dest == -1)
                break;
            int dist; cin >> dist;
            edges[node].push_back({dest, dist});
        }
    }

    int t = get_furthest_node_and_dist(1).first;
    cout << get_furthest_node_and_dist(t).second;
}