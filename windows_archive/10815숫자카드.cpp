#include <iostream>
#include <set>

using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    set<int> _set;
    int n; cin >> n;
    while (n--) 
    {
        int x; cin >> x;
        _set.insert(x);
    }

    int m; cin >> m;
    while (m--)
    {
        int x; cin >> x;
        cout << (_set.find(x) != _set.end()) << ' ';
    }
}