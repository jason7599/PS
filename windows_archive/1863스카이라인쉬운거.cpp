#include <iostream>
#include <stack>

using namespace std;

int ans;
stack<int> s;

void f(int y)
{
    while (s.top() > y)
    {
        s.pop();
        ans++;
    }
    if (s.top() != y)
        s.push(y);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    s.push(0);


    cin >> N;
    while (N--)
    {
        int x, y;
        cin >> x >> y;
        f(y);
    }
    f(0);

    cout << ans;
}