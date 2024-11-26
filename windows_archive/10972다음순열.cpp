#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (next_permutation(arr.begin(), arr.end()))
        for (int i : arr)
            cout << i << ' ';
    else
        cout << -1;
    
    return 0;
}