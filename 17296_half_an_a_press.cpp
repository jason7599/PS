#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int num_stages;
    cin >> num_stages;

    int num_presses = 0;

    while (num_stages--)
    {
        float press_req;
        cin >> press_req;

        int half_presses = press_req * 2;

        if (half_presses)
        {
            if (!num_presses)
            {
                num_presses = (half_presses + 1) / 2;
            }
            else
            {
                num_presses += half_presses / 2;
            }
        }
    }

    cout << num_presses;
    return 0;
}