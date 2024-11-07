#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long long total_length = 0;
    int base = 1;
    int len = 1;

    while (1)
    {
        int n_base = base * 10;
        if (n < n_base)
        {
            total_length += len * (n - base + 1);
            break;
        }

        total_length += 1ll * len * (n_base - base);
        base = n_base;
        len++;
    }

    cout << total_length;
    return 0;
}