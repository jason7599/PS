#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int len;
string str;

int solve(int l, int r)
{
    int best_score = 0;
    for (int i = l - 1; i < r - 1; i++)
    {
        int score = 0;
        int d = min(i - l + 2, r - i - 1);
        for (int j = 0; j < d; j++)
        {
            if (str[i - j] == str[i + 1 + j])
                score++;
        }
        best_score = max(best_score, score);
    }
    return best_score;
}

int main()
{
    int q;
    cin >> len;
    cin >> str;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << solve(l, r) << '\n';
    }
    return 0;
}