#include <bits/stdc++.h>

struct Node
{
    int num;
    Node *next;
};

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n, k;
    std::cin >> n >> k;

    Node *head = new Node{1};

    Node *ptr = head;
    for (int i = 2; i <= n; i++)
        ptr = ptr->next = new Node{i};

    ptr->next = head;

    std::cout << '<';

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k - 1; j++)
            ptr = ptr->next;
        
        Node* selected = ptr->next;

        std::cout << selected->num;
        if (i != n - 1)
            std::cout << ", ";

        ptr->next = selected->next;

        delete selected;
    }

    std::cout << ">\n";
}