#include <iostream>

using namespace std;

bool is_composite[1'000'001];

void sieve_of_eratosthenese(int end)
{
    is_composite[1] = 1;

    for (int i = 2; i * i <= end; i++)
    {
        if (!is_composite[i])
        {
            for (int j = i * i; j <= end; j += i)
                is_composite[j] = 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int start, end;
    cin >> start >> end;

    sieve_of_eratosthenese(end);

    for (int i = start; i <= end; i++)
    {
        if (!is_composite[i])
            cout << i << '\n';
    }

    return 0;
}