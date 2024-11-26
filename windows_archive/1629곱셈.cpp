#include <iostream>

using namespace std;

using ll = long long;

/**
 * a^2n mod m = (a^n mod m)^2 mod m
 */
ll POW(ll a, ll n, ll m)
{
    if (n == 1)
        return a % m;

    ll val = POW(a, n / 2, m);
    val = val * val % m;
    
    if (n % 2 == 1)
        return val * a % m;
    return val;
}

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;
    cout << POW(a, b, c);
}