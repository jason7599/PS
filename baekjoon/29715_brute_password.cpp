#include <iostream>

using namespace std;

int factorial(int n)
{
    static int memo[10];

    if (!n)
        return 1;

    if (memo[n])
        return memo[n];
    
    return memo[n] = n * factorial(n - 1);
}

int main()
{
    int pw_len, num_clues;
    cin >> pw_len >> num_clues;

    int attempt_time, lockout_time;
    cin >> attempt_time >> lockout_time;

    int num_fixed = 0;
    int num_unsure = 0;

    while (num_clues--)
    {
        int pos, val;
        cin >> pos >> val;

        if (pos)
            num_fixed++;
        else
            num_unsure++;
    }

    int num_attempts = 
        factorial(9 - num_fixed - num_unsure) / (factorial(pw_len - num_fixed - num_unsure) * factorial(9 - pw_len))
        * factorial(pw_len - num_fixed) - 1;
    
    cout << (num_attempts + 1) * attempt_time + num_attempts / 3 * lockout_time;

    return 0;
}