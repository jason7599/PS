#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a = 0;
    while (n--)
    {
        char c;
        cin >> c;
        if (c == '1')
            a++;
    }
    cout << a;
    return 0;
}