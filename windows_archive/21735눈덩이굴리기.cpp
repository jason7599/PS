#include <iostream>

using namespace std;

int road_len;
int snow[100];
int best_size;

void solve(int position, int cur_size, int seconds)
{
    if (position == road_len - 1 || seconds == 0)
    {
        if (cur_size > best_size)
            best_size = cur_size;
        return;
    }

    solve(position + 1, cur_size + snow[position + 1], seconds - 1);

    if (position + 2 < road_len)
        solve(position + 2, cur_size / 2 + snow[position + 2], seconds - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int seconds;
    cin >> road_len >> seconds;

    for (int i = 0; i < road_len; i++)
        cin >> snow[i];

    solve(-1, 1, seconds);

    cout << best_size;
    return 0;
}