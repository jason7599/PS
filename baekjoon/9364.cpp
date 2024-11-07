#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int x;
        cin >> x;

        int res = 0;

        int coeff = 0;
        bool coeff_neg = 0;
        bool coeff_empty = 1;

        int exp = 0;
        bool constant = 1;

        const bool read_exp = 0;
        const bool read_coeff = 1;

        bool state = read_coeff;
    
        bool first = 1;

        string s;
        cin >> s;
        for (char c : s)
        {
            switch (c)
            {
            case 'X':
                state = read_exp;
                exp = 0;
                constant = 0;
                break;

            case '^':
                break;

            case '+':
            case '-':
                if (!first)
                    res += (coeff_neg ? -1 : 1) 
                        * (coeff_empty ? 1 : coeff)
                        * pow(x, (constant ? 0 : (exp ? exp : 1)));
                
                state = read_coeff;
                coeff = 0;
                coeff_empty = 1;
                coeff_neg = c == '-';

                constant = 1;
                break;

            default:
                int n = c - '0';
                if (state == read_coeff)
                {
                    coeff = coeff * 10 + n;
                    coeff_empty = 0;
                }
                else
                    exp = exp * 10 + n;
                break;
            }

            first = 0;
        }

        res += (coeff_neg ? -1 : 1) 
            * (coeff_empty ? 1 : coeff)
            * pow(x, (constant ? 0 : (exp ? exp : 1)));

        cout << "Case #" << i << ": " << res << '\n';
    }

    return 0;
}