#include <iostream>

using namespace std;

struct Balloon
{
    int val;
    bool popped;
};

Balloon balloons[1'000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int num_balloons;
    cin >> num_balloons;

    for (int i = 0; i < num_balloons; i++)
    {
        cin >> balloons[i].val;
    }

    int balloon_index = 0;

    for (int i = 0; i < num_balloons - 1; i++)
    {
        cout << balloon_index + 1 << ' ';

        balloons[balloon_index].popped = true;
        int val = balloons[balloon_index].val;

        int d = val < 0 ? -1 : 1;
        int t = val < 0 ? -val : val;

        while (t)
        {
            balloon_index += d;

            if (balloon_index < 0)
                balloon_index = num_balloons - 1;
            else if (balloon_index >= num_balloons)
                balloon_index = 0;

            if (!balloons[balloon_index].popped)
            {
                t--;
            }
        }
    }

    cout << balloon_index + 1;

    return 0;
}