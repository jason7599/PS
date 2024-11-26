#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string input;
    cin >> input;

    queue<int> xStreak;
    int streak = 0;

    for (char c : input)
    {
        if (c == 'X')
        {
            streak++;
        }
        else
        {
            xStreak.push(streak);
            if (streak)
                xStreak.push(streak = 0);
        }
    }
    if (streak) xStreak.push(streak);


    string res = "";

    while (xStreak.size())
    {
        int cur = xStreak.front();
        xStreak.pop();

        if (cur)
        {
            if (cur % 2)
            {
                cout << - 1;
                return 0;
            }

            while (cur)
            {
                if (cur >= 4)
                {
                    res += "AAAA";
                    cur -= 4;
                }
                else
                {
                    res += "BB";
                    cur -= 2;
                }
            }
        }
        else
        {
            res += '.';
        }
    }

    cout << res;
}