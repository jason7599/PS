#include <iostream>
#include <algorithm>

using namespace std;

int64_t gcd(int64_t a, int64_t b) 
{
    while (b)
    {
        int64_t r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int64_t lcm(int64_t a, int64_t b)
{
    return a * b / gcd(a, b);
}

int main()
{
    int n, k;
    cin >> k >> n;
    int64_t _lcm = 1;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        _lcm = lcm(_lcm, a);
    }
    
    cout << _lcm - k;
    return 0;
}