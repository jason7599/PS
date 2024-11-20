#include <iostream>
#include <string>
#include <cmath>

/**
 * q_digit번째 숫자가 몇자리수 숫자들의 (1)
 * 몇번째 idx가 되는지 (2)
 */
std::pair<u_int64_t, u_int64_t> fuck(u_int64_t q_digit)
{
    u_int64_t len = 1;
    u_int64_t t = 9;
    while (q_digit > t * len)
    {
        q_digit -= t * len;
        t *= 10;
        len++;
    }
    return {len, q_digit - 1};
}


int main()
{
    u_int64_t num, q_digit;
    std::cin >> num >> q_digit;

    auto [len, idx] = fuck(q_digit);

    // # of nums starting from 10^len before 
    // the number in which digit is in
    u_int64_t n_prec = idx / len;
    idx %= len; // idx within the number

    // the real number
    u_int64_t rnum = std::pow(10, len - 1) + n_prec;

    if (rnum > num)
        std::cout << -1;
    else
        std::cout << std::to_string(rnum)[idx];
}