#include <iostream>

using namespace std;

bool solve(int a, int b, int sum = 0)
{
    
}

int main()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (solve(a, b))
            cout << "yes";
        else
            cout << "no";
        cout << '\n';
    }
    return 0;
}