#include <iostream>
#include <string>
#include <cmath>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_tc;
    std::cin >> n_tc;

    while (n_tc--)
    {
        int a, b;
        u_int64_t c;
        std::cin >> a >> b >> c;

        u_int64_t base = a;
        int n_digits = 1;
        u_int64_t dec = 10;

        while (dec <= a)
        {
            dec *= 10;
            n_digits++;
        }

        while (1)
        {
            int cnt = (dec - 1 - a) / b - std::ceil(base - a) / b + 1;
            u_int64_t t = cnt * n_digits;

            if (c <= t)
                break;
            
            c -= t;
            n_digits++;
            dec *= 10;
            base += cnt * b;
        }
        // now c - 1 is the index of the string that starts from base

        int n_prec = (c - 1) / n_digits;
        u_int64_t num = base + n_prec * b; // the number c is included in

        std::cout << std::to_string(num)[(c - 1) % n_digits] << '\n';
    }
}