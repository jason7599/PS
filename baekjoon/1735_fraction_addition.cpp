#include <iostream>
#include <algorithm>

int main()
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    int numerator = a * d + c * b;
    int denominator = b * d;

    int gcd = std::__gcd(numerator, denominator);

    std::cout << numerator / gcd << ' ' << denominator / gcd;
}