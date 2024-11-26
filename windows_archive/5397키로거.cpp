#include <iostream>
#include <string>

using namespace std;

struct Node
{
    char val;
    Node* next = nullptr;
    Node* prev = nullptr;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int num_input; 
    cin >> num_input;

    while (num_input--)
    {
        string input; 
        cin >> input;

        Node head;
        Node* ptr = &head;

        for (char c : input)
        {
            switch (c)
            {
            case '<':
                if (ptr->prev != nullptr)
                    ptr = ptr->prev;
                break;
            case '>':
                if (ptr->next != nullptr)
                    ptr = ptr->next;
                break;
            case '-':
                if (ptr == &head)
                    continue;
                ptr->prev->next = ptr->next;
                if (ptr->next != nullptr)
                    ptr->next->prev = ptr->prev;
                ptr = ptr->prev;
                break;
            default:
                Node* node = (Node*)malloc(sizeof(Node));
                node->val = c;
                if (ptr->next != nullptr)
                    ptr->next->prev = node;
                node->prev = ptr;
                node->next = ptr->next;
                ptr->next = node;
                ptr = node;
            }
        }

        ptr = head.next;
        while (ptr != nullptr)
        {
            cout << ptr->val;
            Node* temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
        cout << '\n';
    }
}