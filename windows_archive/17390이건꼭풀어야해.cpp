#include <iostream>
#include <algorithm>

using namespace std;

int arr[300'001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int len, numQuestions;
    cin >> len >> numQuestions;

    for (int i = 1; i <= len; i++)
        cin >> arr[i];

    sort(arr + 1, arr + 1 + len);

    for (int i = 1; i <= len; i++)
        arr[i] += arr[i - 1];

    while (numQuestions--)
    {
        int l, r;
        cin >> l >> r;
        cout << arr[r] - arr[l - 1] << '\n';
    }

    return 0;
}