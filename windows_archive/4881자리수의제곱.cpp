#include <iostream>
#include <algorithm>

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
    int ans = 1e9;
    while (!b_path[b])
    {
        if (b == a)
            ans = min(ans, i + 1);
        
        if (a_path[b])
        {
            // cout << "!!!" << b << "!!!\n";
            // return i + a_path[b] + 1;
            ans = min(ans, i + a_path[b] + 1);
        }

        
        b_path[b] = 1;
        b = fuck(b);
        i++;
    }

    return ans == 1e9 ? 0 : ans;
}

#include <vector>
#include <set>

vector<int> get_path(int a)
{
    set<int> visited;
    vector<int> path;

    while (visited.find(a) == visited.end())
    {
        visited.insert(a);
        path.push_back(a);
        a = fuck(a);
    }

    return path;
}

void print_path(const vector<int>& path)
{
    cout << path[0];
    for (int i = 1; i < path.size(); i++)
        cout << " -> " << path[i];
    cout << '\n';
}

int brute_solve(int a, int b)
{
    vector<int> a_path = get_path(a);
    vector<int> b_path = get_path(b);

    for (int ai = 0; ai < a_path.size(); ai++)
    {
        for (int bi = 0; bi < b_path.size(); bi++)
        {
            if (a_path[ai] == b_path[bi])
                return ai + bi + 2;
        }
    }

    return 0;
}

void explain(int a, int b)
{

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // while (1)
    // {
    //     int a, b;
    //     cin >> a >> b;
    //     if (!a)
    //         break;
    //     cout << a << ' ' << b << ' ' << solve(a, b) << '\n';
    // }

    // return 0;

    cout << "\n\n\n\n\n\n\n";
    cout << "\n\n\n\n\n\n\n";

    // auto p = get_path(15);

    // print_path(p);

    // cout << brute_solve(89, 89) << '\n';

    // srand(time(nullptr));
    // for (int i = 0; i < 100; i++)
    // {
    //     int a = max(rand(), 1);
    //     int b = max(rand(), 1);

    //     int my_ans = solve(a, b);
    //     int ans = brute_solve(a, b);

    //     if (my_ans != ans)
    //     {
    //         printf("a = %d, b = %d -> my_ans = %d, ans = %d\n", a, b, my_ans, ans);
    //         break;
    //     }
    // }

    // !!! a = 16819, b = 15413 -> my_ans = 13, ans = 17
    int a = 16819; int b = 15413;

    print_path(get_path(a));
    print_path(get_path(b));

    // 16819 -> 183 -> 74 -> 65 -> 61 -> 37 -> 58 -> 89 -> 145 -> 42 -> 20 -> 4 -> 16
    // 15413 -> 52 -> 29 -> 85 -> 89 -> 145 -> 42 -> 20 -> 4 -> 16 -> 37 -> 58
}