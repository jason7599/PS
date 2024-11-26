#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int num_nums, target;
        cin >> num_nums >> target;

        map<int, int> map;
        for (int i = 0; i < num_nums; i++)
        {
            int x;
            cin >> x;
            map[x]++;
        }

        int ans = 0;
        
    }

    return 0;
}