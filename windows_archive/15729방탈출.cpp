#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num_buttons;
    cin >> num_buttons;

    bool next = 0;
    bool nnext = 0;
    int num_presses = 0;
    for (int i = 0; i < num_buttons; i++)
    {
        bool cur = next;
        next = nnext;
        nnext = 0;

        bool target;
        cin >> target;

        if (cur != target)
        {
            num_presses++;
            next = !next;
            nnext = !nnext;
        }
    }

    cout << num_presses;
    return 0;
}