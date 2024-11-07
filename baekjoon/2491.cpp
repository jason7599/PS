#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    int prev;
    cin >> prev;

    int max_inc_streak = 1;
    int max_dec_streak = 1;

    int inc_streak = 1;
    int dec_streak = 1;

    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;

        if (x == prev)
        {
            inc_streak++;
            dec_streak++;
        }
        else if (x > prev)
        {
            inc_streak++;
            dec_streak = 1;
        }
        else
        {
            dec_streak++;
            inc_streak = 1;
        }
        
        max_inc_streak = max(max_inc_streak, inc_streak);
        max_dec_streak = max(max_dec_streak, dec_streak);

        prev = x;
    }

    cout << max(max_inc_streak, max_dec_streak);
    return 0;
}