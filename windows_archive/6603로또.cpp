#include <iostream>

using namespace std;

void comb(const int S[], int k, int index = 0)
{
    static int chosen[13];
    static int chosen_len = 0;

    if (chosen_len == 6)
    {
        for (int i = 0; i < 6; i++)
            cout << chosen[i] << ' ';
        cout << '\n';
        return;
    }

    if (index == k)
        return;

    // S[index] chosen
    chosen[chosen_len++] = S[index];
    comb(S, k, index + 1);
    chosen_len--;

    // Skip S[index]
    comb(S, k, index + 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int S[13], k;

    while (true)
    {
        cin >> k;
        if (!k)
            break;
        for (int i = 0; i < k; i++)
            cin >> S[i];

        comb(S, k);
        cout << '\n';
    }
}