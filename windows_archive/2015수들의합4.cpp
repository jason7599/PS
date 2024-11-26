#include <iostream>

using namespace std;

int arr[200'000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, k, sum = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] = sum = sum + x;
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';

    return 0;
}