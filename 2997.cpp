#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[3];
    
    for (int i = 0; i < 3; i++)
        cin >> arr[i];
    
    sort(arr, arr + 3);

    int diff0 = arr[1] - arr[0];
    int diff1 = arr[2] - arr[1];

    if (diff0 == diff1)
        cout << arr[2] + diff0;
    else if (diff0 = diff1 * 2)
        cout << arr[0] + diff1;
    // else if (diff1 = diff0 * 2)
    else
        cout << arr[1] + diff0;

    return 0;
}