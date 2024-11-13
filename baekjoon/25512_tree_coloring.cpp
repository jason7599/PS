#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int white_cost;
    int black_cost;
    vector<int> children;
};

Node tree[100'000];

long long solve(int node, bool white)
{
    long long res = 0;
    for (int child : tree[node].children)
        res += solve(child, !white);

    return res +
        (white ? tree[node].white_cost : tree[node].black_cost);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int num_nodes;
    cin >> num_nodes;

    for (int i = 0; i < num_nodes - 1; i++)
    {
        int parent, child;
        cin >> parent >> child;
        tree[parent].children.push_back(child);
    }

    for (int i = 0; i < num_nodes; i++)
        cin >> tree[i].white_cost >> tree[i].black_cost;

    cout << min(solve(0, 0), solve(0, 1));
    return 0;
}