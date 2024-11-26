#include <iostream>

using namespace std;

int main()
{
    int seq_len;
    int seq[50];
    int a, b;
    int d0, d1;

    cin >> seq_len;
    for (int i = 0; i < seq_len; i++)
        cin >> seq[i];

    if (seq_len == 1)
        goto A;

    d0 = seq[1] - seq[0];

    if (seq_len == 2)
    {
        if (d0 == 0) // repeat
        {
            cout << seq[0];
            return 0;
        }
        else
            goto A;
    }
    
    d1 = seq[2] - seq[1];
    if (d0 == 0)
    {
        if (d1 == 0)
        {
            a = 1;
            b = 0;
        }
        else
            goto B;
    }
    else
    {
        if (d1 % d0 != 0)
            goto B;
        
        a = d1 / d0;
        b = seq[1] - seq[0] * a;
    }

    for (int i = 2; i < seq_len; i++)
    {
        if (seq[i] != seq[i - 1] * a + b)
            goto B;
    }

    cout << seq[seq_len - 1] * a + b;
    return 0;
A:
    cout << 'A';
    return 0;
B:
    cout << 'B';
    return 0;
}