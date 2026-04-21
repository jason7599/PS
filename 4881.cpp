#include <iostream>

using namespace std;

int fuck(int n)
{
    int v = 0;
    while (n)
    {
        v += (n % 10) * (n % 10);
        n /= 10;
    }
    return v;
}

int solve(int a, int b)
{
    if (a == b)
        return 2;

    int a_path[730] = {0};
    bool b_path[730] = {0};
    int i;

    int _a = fuck(a);
    i = 1;
    while (!a_path[_a])
    {
        if (_a == b)
            return i + 2;
        a_path[_a] = i++;
        _a = fuck(_a);
    }

    b = fuck(b);
    i = 2;
    while (!b_path[b])
    {
        if (b == a)
            return i + 1;
        
        if (a_path[b])
            return i + a_path[b] + 1;

        b_path[b] = 1;
        b = fuck(b);
        i++;
    }

    return 0;
}

#include <map>
#include <set>

uint brute_solve(int a, int b)
{
    map<int, uint> a_path;
    uint i = 1;

    while (a_path.find(a) == a_path.end())
    {
        a_path[a] = i++;
        a = fuck(a);
    }

    set<int> b_path;
    i = 1;
    while (b_path.find(b) == b_path.end())
    {
        b_path.insert(b);

        if (a_path.find(b) != a_path.end())
        {
            return i + a_path[b];
        }

        i++;
        b = fuck(b);
    }

    return 0;
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);

    while (1)
    {
        int a, b;
        cin >> a >> b;
        
        if (!a)
            break;
    
        cout << a << ' ' << b << ' ' << brute_solve(a, b) << '\n';
    }

    return 0;
}