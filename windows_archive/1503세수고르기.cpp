#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int target;
set<int> exclude;
int min_diff = 1e9;

void solve(int index = 0, int val = 1)
{
    if (index == 3)
    {
        min_diff = min(min_diff, abs(target - val));
        return;
    }

    for (int num = 1;; num++)
    {
        if (exclude.find(num) == exclude.end())
        {
            solve(index + 1, val * num);
            if (val * num >= target)
                break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int m;
    cin >> target >> m;
    while (m--)
    {
        int x;
        cin >> x;
        exclude.insert(x);
    }

    solve();

    cout << min_diff;
    return 0;
}