#include <iostream>

using namespace std;

pair<int, int> mem[2][46]; // mem[0] = A, mem[1] = B

pair<int, int> solve(int k, int i = 0)
{
    if (k == 0)
    {
        if (i == 0)
            return {1, 0};
        return {0, 1};
    }

    if (mem[i][k].first != 0 || mem[i][k].second != 0)
        return mem[i][k];

    pair<int, int> res = solve(k - 1, 1);
    
    if (i == 1)
    {
        pair<int, int> temp = solve(k - 1, 0);
        res.first += temp.first;
        res.second += temp.second;
    }

    return mem[i][k] = res;
}

int main()
{
    int k;
    cin >> k;

    pair<int, int> ans = solve(k);
    cout << ans.first << ' ' << ans.second;

    return 0;
}