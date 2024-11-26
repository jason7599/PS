#include <iostream>
#include <string>
#include <set>

using namespace std;

bool fuck(const string& str, int k)
{
    set<pair<int,int>> visited;

    int y1 = 0;
    int x1 = 0;

    for (char c : str)
    {
        switch (c)
        {
            case 'U': y1--; break;
            case 'D': y1++; break;
            case 'R': x1++; break;
            case 'L': x1--; break;
        }

        if (y1 == 0 && x1 == 0)
            return true;

        visited.insert({y1, x1});
    }

    for (auto point : visited)
    {
        int y = point.first;
        int x = point.second;

        if (y1 * y > 0 || x1 * x > 0)
            continue;
    }

    return false;
}

int main()
{
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;

    if (fuck(str, k))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}