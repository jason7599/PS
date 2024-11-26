#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int, int> m;
    int n; cin >> n;
    while (n--)
    {
        int x; cin >> x;
        m[x]++;
    }
    cin >> n;
    while (n--)
    {
        int x; cin >> x;
        cout << m[x] << ' ';
    }
}