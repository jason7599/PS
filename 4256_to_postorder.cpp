#include <iostream>

int n_nodes;
int preorder[1000];
int inorder[1000];

void postorder(int pre_l, int in_l, int len)
{
    if (!len)
        return;

    int p = preorder[pre_l];

    int in_p = in_l;
    while (inorder[in_p] != p)
        in_p++;

    int len_r = in_l + len - in_p - 1;
    int len_l = in_p - in_l;

    postorder(pre_l + 1, in_l, len_l);
    postorder(pre_l + len_l + 1, in_p + 1, len_r);

    std::cout << p << ' ';
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_tc;
    std::cin >> n_tc;

    while (n_tc--)
    {
        std::cin >> n_nodes;
        for (int i = 0; i < n_nodes; i++)
            std::cin >> preorder[i];
        for (int i = 0; i < n_nodes; i++)
            std::cin >> inorder[i];
        postorder(0, 0, n_nodes);
        std::cout << '\n';
    }
}