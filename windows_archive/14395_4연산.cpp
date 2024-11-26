#include <iostream>
#include <string>
#include <queue>

#define WTF 31623

using namespace std;

string solve(int start, int target)
{
    if (start == target) return "0";

    queue<pair<int, string>> q;

    if (start < WTF) q.push({start * start, "*"});
    q.push({start * 2, "+"});
    q.push({1, "/"});

    while (!q.empty())
    {
        int num = q.front().first;
        string str = q.front().second;
        q.pop();

        if (num == target) return str;
        if (num > target) continue;

        if (num != 1 && num < WTF) q.push({num * num, str + "*"});
        q.push({num * 2, str + "+"});
    }
        
    return "-1";
}

int main()
{
    int start, target;
    cin >> start >> target;
    cout << solve(start, target);
}