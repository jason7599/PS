#include <iostream>
#include <string>

using namespace std;

string add(int a, int b)
{
    string res;

    while (a || b)
    {
        res = to_string(a % 10 + b % 10) + res;
        a /= 10;
        b /= 10;
    }

    return res;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << add(a, b);
    return 0;
}