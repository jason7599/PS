#include <iostream>

using namespace std;

int inorder[100'000];
int postorder[100'000];

void preorder(int inorder_start, int postorder_start, int len)
{
    if (!len) return;

    int parent = postorder[postorder_start + len - 1];

    cout << parent << ' ';

    int parent_inorder_index;
    for (parent_inorder_index = inorder_start; inorder[parent_inorder_index] != parent; parent_inorder_index++);

    int left_len = parent_inorder_index - inorder_start;
    preorder(inorder_start, postorder_start, left_len);
    
    int right_len = len - left_len - 1;
    preorder(parent_inorder_index + 1, postorder_start + left_len, right_len);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int num_vertices;
    cin >> num_vertices;

    for (int i = 0; i < num_vertices; i++)
        cin >> inorder[i];

    for (int i = 0; i < num_vertices; i++)
        cin >> postorder[i];

    preorder(0, 0, num_vertices);
}