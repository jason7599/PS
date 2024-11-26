#include <iostream>

using namespace std;

int arr0[1'000'000];
int arr1[1'000'000];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> arr0[i];
    
    for (int i = 0; i < m; i++)
        cin >> arr1[i];

    int l = 0, r = 0;
    while (l < n || r < m)
    {
        if (arr0[l] < arr1[r])
        {
            cout << arr0[l++];
        }
        else
        {
            cout << arr1[r++];
        }
        cout << ' ';
    }

    return 0;
}