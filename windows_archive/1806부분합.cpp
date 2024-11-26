#include <iostream>

using namespace std;

int arr[100'000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, s, sum = 0;
    cin >> n >> s;

    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        sum = arr[i] = sum + x;
        if (sum > s)
        {
            cout << 1;
            return 0;
        }
        // for (int l = 1; i - l >= 0; l++)

    }
}