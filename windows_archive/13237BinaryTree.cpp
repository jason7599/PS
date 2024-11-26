#include <iostream>

using namespace std;

struct Node
{
    int left;
    int right;
    int height;
};

int numNodes;
Node tree[21];

void dfs(int parent, int height = 0)
{
    Node& node = tree[parent];
    node.height = height;

    if (node.left)
        dfs(node.left, height + 1);
    if (node.right)
        dfs(node.right, height + 1);
}

int main()
{
    cin >> numNodes;

    int rootNode;

    for (int i = 1; i <= numNodes; i++)
    {
        int parent;
        cin >> parent;

        if (parent == -1)
            rootNode = i;
        else
        {
            if (tree[parent].left)
                tree[parent].right = i;
            else
                tree[parent].left = i;
        }
    }

    dfs(rootNode);

    for (int i = 1; i <= numNodes; i++)
        cout << tree[i].height << '\n';

    return 0;
}
