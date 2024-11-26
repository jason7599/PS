#include <iostream>
#include <string>

using namespace std;

string preorder, inorder;

void print_postorder(int parent_preorder_index = 0, int inorder_begin = 0, int len = preorder.length())
{
    char parent = preorder[parent_preorder_index];

    if (len == 1)
    {
        cout << parent;
        return;
    }

    int parent_inorder_index = inorder.find(parent, inorder_begin);
    int left_len = parent_inorder_index - inorder_begin;

    if (left_len) print_postorder(parent_preorder_index + 1, inorder_begin, left_len);
    
    int right_len = len - left_len - 1;
    if (right_len) print_postorder(parent_preorder_index + left_len + 1, parent_inorder_index + 1, right_len);

    cout << parent;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (1)
    {
        cin >> preorder >> inorder;

        if (cin.eof())
            break;

        print_postorder();
        cout << '\n';
    }
}