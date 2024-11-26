#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        map<string, int> count_by_kind;
        int num_clothes; cin >> num_clothes;
        while (num_clothes--)
        {
            string name, kind;
            cin >> name >> kind;
            count_by_kind[kind]++;
        }
        int res = 1;
        for (auto x : count_by_kind)
            res *= x.second + 1;
        cout << res - 1 << '\n';
    }
}