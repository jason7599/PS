#include <iostream>
#include <string>

using namespace std;

int A[2000][26];
int T[26];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string input;
    cin >> input;

    for (int i = 0; i < input.length(); i++)
    {
        T[input[i] - 'a']++;
        for (int j = 0; j < 26; j++)
        {
            A[i][j] = T[j];
        }
    }

    int k; cin >> k;

    while (k--)
    {
        char c;
        int l, r;

        cin >> c >> l >> r;

        int y = A[r][c - 'a'];
        int x = l ? A[l - 1][c - 'a'] : 0;

        cout << y - x << '\n';
    }

}