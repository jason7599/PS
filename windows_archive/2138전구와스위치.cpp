#include <iostream>
#include <bitset>

using namespace std;

const int max_bit_len = 100'000;

int bit_len;
bitset<max_bit_len> src, dest;

int main()
{
    cin >> bit_len;

    for (int i = 0; i < bit_len; i++)
    {
        char c; cin >> c;
        if (c == '1')
            src.set(i);
    }
    for (int i = 0; i < bit_len; i++)
    {
        char c; cin >> c;
        if (c == '1')
            dest.set(i);
    }

    int flip = 0;
    for (int i = 0; i < bit_len; i++)
    {
        if (src[i] != dest[i])
        {
            
        }
    }
}