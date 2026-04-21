#include <iostream>
#include <algorithm>

using namespace std;

bool not_prime[1'001];

void sieve(int max)
{
    for (int i = 2; i * i <= max; i++)
    {
        if (!not_prime[i])
        {
            for (int j = i * i; j <= max; j += i)
                not_prime[j] = 1;
        }
    }
}

int main()
{
    int a, b;
    int c, d;

    cin >> a >> b;
    cin >> c >> d;

    sieve(max(b, d));

    int yt_cnt = 0;
    int yj_cnt = 0;
    int yy_cnt = 0;

    for (int i = min(a, c); i <= max(b, d); i++)
    {
        if (!not_prime[i])
        {
            bool yt = a <= i && i <= b;
            bool yj = c <= i && i <= d;

            if (yt)
                yt_cnt++;
            if (yj)
            {
                if (yt)
                    yy_cnt++;
                yj_cnt++;
            }
        }
    }

    if (yy_cnt % 2)
        cout << (yt_cnt + 1 > yj_cnt ? "yt" : "yj");
    else
        cout << (yt_cnt > yj_cnt ? "yt" : "yj");

    return 0;
}