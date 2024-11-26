#include <iostream>

using namespace std;

struct Node
{
    int left;
    int right;
    int x;
};

Node nodes[10'001];
int next_x = 1;
int max_level;
int level_min_x[10'001];
int level_max_x[10'001];

void map_x_values_recursive(int node_index, int level)
{
    Node *parent = &nodes[node_index];

    if (parent->left != -1)
        map_x_values_recursive(parent->left, level + 1);

    parent->x = next_x++;

    if (!level_min_x[level])
        level_min_x[level] = parent->x;
    
    level_max_x[level] = parent->x;

    if (level > max_level)
        max_level = level;

    if (parent->right != -1)
        map_x_values_recursive(parent->right, level + 1);
}

int main()
{
    int num_nodes;
    scanf("%d", &num_nodes);
    
    int topology[10'001] = {0};

    for (int i = 0; i < num_nodes; i++)
    {
        int parent, left, right;
        scanf("%d %d %d", &parent, &left, &right);

        nodes[parent] = Node{left, right};

        if (left != -1) topology[left] = parent;
        if (right != -1) topology[right] = parent;
    }

    int root_index;
    for 
    (
        root_index = 1; 
        topology[root_index]; 
        root_index = topology[root_index]
    );

    map_x_values_recursive(root_index, 1);

    int max_width = 1;
    int max_width_level = 1;

    for (int level = 2; level <= max_level; level++)
    {
        int width = level_max_x[level] - level_min_x[level] + 1;
        if (width > max_width)
        {
            max_width = width;
            max_width_level = level;
        }
    }

    printf("%d %d\n", max_width_level, max_width);
    
    return 0;
}