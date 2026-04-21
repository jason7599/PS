#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[500'001];

int total_dist;

void dfs(int node_idx, int prev = -1, int dist = 0)
{
    if (prev != -1 && tree[node_idx].size() == 1)
    {
        total_dist += dist;
        return;
    }

    for (int child : tree[node_idx])
    {
        if (child != prev)
            dfs(child, node_idx, dist + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int num_nodes;
    cin >> num_nodes;
    for (int i = 0; i < num_nodes - 1; i++)
    {
        int node0, node1;
        cin >> node0 >> node1;
        tree[node0].push_back(node1);
        tree[node1].push_back(node0);
    }

    dfs(1);

    if (total_dist % 2)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}