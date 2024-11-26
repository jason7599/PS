#include <iostream>
#include <queue>

using namespace std;

#define MAX_NODES 200000

int get_min_paint(int desired_colors[], vector<int> adj_matrix[])
{
    bool visited[MAX_NODES + 1] = {false};
    queue<pair<int,int>> q; // <node num, color>

    visited[1] = true;
    q.push({1, 0});

    int paint = 0;

    while (!q.empty())
    {
        int node_num = q.front().first;
        int color = q.front().second;
        q.pop();

        if (color != desired_colors[node_num])
        {
            color = desired_colors[node_num];
            paint++;
        }

        for (int adj : adj_matrix[node_num])
        {
            if (!visited[adj])
            {
                visited[adj] = true;
                q.push({adj, color});
            }
        }
    }

    return paint;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int num_nodes;
    int desired_colors[MAX_NODES + 1];

    cin >> num_nodes;

    for (int i = 1; i <= num_nodes; i++)
    {
        cin >> desired_colors[i];
    }

    vector<int> adj_matrix[MAX_NODES + 1];

    for (int i = 0; i < num_nodes - 1; i++)
    {
        int from, to; cin >> from >> to;
        adj_matrix[from].push_back(to);
        adj_matrix[to].push_back(from);
    }

    cout << get_min_paint(desired_colors, adj_matrix);
}