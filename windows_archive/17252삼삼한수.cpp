#include <iostream>

using namespace std;

bool samsam(int n)
{
    if (!n)
        return false;

    int64_t p = 1;
    while (p * 3 <= n)
        p *= 3;
    
    while (n && p)
    {
        if (n >= p)
            n -= p;
        p /= 3;
    }

    return !n;
}

int main()
{
    int n;
    cin >> n;
    if (samsam(n))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}