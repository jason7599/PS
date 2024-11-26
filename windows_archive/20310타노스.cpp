#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int len = 0;
    bool str[500];

    int num_zeros = 0;
    int num_ones = 0;

    char c;
    while ((c = getchar()) != '\n')
    {
        if ((str[len++] = c == '1'))
            num_ones++;
        else
            num_zeros++;
    }

    int zero_cnt = 0;
    int one_cnt = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i])
        {
            if (++one_cnt > num_ones / 2)
                cout << 1;
        }
        else
        {
            if (++zero_cnt <= num_zeros / 2)
                cout << 0;
        }
    }

    return 0;
}