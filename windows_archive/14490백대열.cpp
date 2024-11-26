#include <iostream>

using namespace std;

int gcd(int n, int m)
{
    if (m == 0)
        return n;
    return gcd(m, n % m);
}

int main()
{
    int n, m;
    scanf("%d:%d", &n, &m);

    int x = gcd(n, m);

    printf("%d:%d", n / x, m / x);
}